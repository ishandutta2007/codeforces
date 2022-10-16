#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
//#define size(n) ((int)(n).size())
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int n,vis[MAX],x,res;
bool p[MAX],st[MAX];
vector<int> fc[MAX];
char c;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(ll i = 2; i<MAX; ++i)if(!p[i]){
    	for(ll j = i; j<MAX; j+=i){
    		p[j] = 1;
    		fc[j].pb(i);
		}
	}
	cin>>n>>n;
	while(n--){
		cin>>c>>x;
		if(c=='+'){
			if(st[x])cout<<"Already on\n";
			else {
				res = 0;
				for(int i:fc[x])if(vis[i]){
					res = vis[i];
					break;
				}
				if(res)cout<<"Conflict with "<<res<<endl;
				else {
					cout<<"Success\n";
					for(int i:fc[x])vis[i] = x;
					st[x] = 1;
				}
			}
		}
		else {
			if(!st[x])cout<<"Already off\n";
			else {
				cout<<"Success\n";
				for(int i:fc[x])vis[i] = 0;
				st[x] = 0;
			}
		}
	}
    return 0;
}