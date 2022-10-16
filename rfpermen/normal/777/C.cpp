#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,m,q,a,b,ls;
bool pre[block][block],st;
vector<int> x[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,0,m)x[0].pb(0);
    rep(i,1,n){
    	x[i].pb(0);
    	rep(j,1,m)x[i].pb(0), cin>>x[i][j];
	}
	if(n<block){
		rep(j,1,m){
			rep(i,1,n){
				rep(k,i+1,n){
					if(x[k-1][j]>x[k][j])break;
					pre[i][k] = 1;
				}
			}
		}
		cin>>q;
		while(q--){
			cin>>a>>b;
			cout<<(a==b || pre[a][b] ? "Yes\n" : "No\n");
		}
	}
	else {
		rep(j,1,m)rep(i,2,n)x[i-1][j] = x[i-2][j] + (x[i-1][j]<=x[i][j]);
		cin>>q;
		while(q--){
			cin>>a>>b;
			if(a==b){cout<<"Yes\n"; continue;}
			st = 0;
			rep(j,1,m)if(x[b-1][j]-x[a-1][j]==b-a){st = 1; break;}
			cout<<(st ? "Yes\n" : "No\n");
		}
	}
    return 0;
}