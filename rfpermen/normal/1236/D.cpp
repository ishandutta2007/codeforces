#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,m,a,b,k,x,y,res,st;
vector<int> r[MAX],c[MAX];
set<pii> s;

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    while(k--){
    	cin>>x>>y;
    	r[x].pb(y);
    	c[y].pb(x);
    	s.insert({x,y});
	}
	a = b = 1;
	x = 1, y = 0, st = 1;
	while(a<=n&&b<=m){
		if(st==1){
			b = y+1;
			res = -1;
			for(auto i:r[x]){
				if(i<=m&&i>=b){
					if(res==-1)res = i;
					else res = min(res,i);
				}
			}
			if(res==-1)y = m;
			else {
				rep(i,a,n)rep(j,res,m){
					if(!s.count({i,j}))return cout<<"No\n",0;
				}
				y = res-1;
			}
		}
		else if(st==2){
			a = x+1;
			res = -1;
			for(auto i:c[y]){
				if(i<=n&&i>=a){
					if(res==-1)res = i;
					else res = min(res,i);
				}
			}
			if(res==-1)x = n;
			else {
				rep(i,res,n)rep(j,b,m){
					if(!s.count({i,j}))return cout<<"No\n",0;
				}
				x = res-1;
			}
		}
		else if(st==3){
			m = y-1;
			res = -1;
			for(auto i:r[x]){
				if(i<=m&&i>=b){
					if(res==-1)res = i;
					else res = max(res,i);
				}
			}
			if(res==-1)y = b;
			else {
				rep(i,a,n)rep(j,b,res){
					if(!s.count({i,j}))return cout<<"No\n",0;
				}
				y = res+1;
			}
		}
		else {
			n = x-1;
			res = -1;
			for(auto i:c[y]){
				if(i<=n&&i>=a){
					if(res==-1)res = i;
					else res = max(res,i);
				}
			}
			if(res==-1)x = a;
			else {
				rep(i,a,res)rep(j,b,m){
					if(!s.count({i,j}))return cout<<"No\n",0;
				}
				x = res+1;
			}
		}
		++st;
		if(st==5)st-=4;
	}
	cout<<"Yes\n";
    return 0;
}