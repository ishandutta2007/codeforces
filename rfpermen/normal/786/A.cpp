#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
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
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,a,b,x[MAX],y[MAX],cnt[MAX],cnt2[MAX],nw,nx;
bool vis[MAX],vis2[MAX];
stack<int> s,k;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("asd.csv", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	cin>>a;
	rep(i,1,a)cin>>x[i];
	cin>>b;
	rep(i,1,b)cin>>y[i];
	rep(i,1,a)s.push(n-x[i]), vis[n-x[i]] = 1;
	while(!(s.empty() && k.empty())){
		while(!s.empty()){
			nw = s.top(), s.pop();
			rep(i,1,b){
				nx = (nw+n-y[i])%n;
				if(!nx)continue;
				if(cnt[nx]!=b){
					++cnt[nx];
					if(cnt[nx]==b)k.push(nx);
				}
			}
		}
		while(!k.empty()){
			nw = k.top(), k.pop();
			rep(i,1,a){
				nx = (nw+n-x[i])%n;
				if(!nx)continue;
				if(!vis[nx]){
					vis[nx] = 1;
					s.push(nx);
				}
			}
		}
	}
	rep(i,1,b)s.push(n-y[i]), vis2[n-y[i]] = 1;
	while(!(s.empty() && k.empty())){
		while(!s.empty()){
			nw = s.top(), s.pop();
			rep(i,1,a){
				nx = (nw+n-x[i])%n;
				if(!nx)continue;
				if(cnt2[nx]!=b){
					++cnt2[nx];
					if(cnt2[nx]==a)k.push(nx);
				}
			}
		}
		while(!k.empty()){
			nw = k.top(), k.pop();
			rep(i,1,b){
				nx = (nw+n-y[i])%n;
				if(!nx)continue;
				if(!vis2[nx]){
					vis2[nx] = 1;
					s.push(nx);
				}
			}
		}
	}
	For(i,1,n){
		if(vis[i])cout<<"Win ";
		else if(cnt2[i]==a)cout<<"Lose ";
		else cout<<"Loop ";
	}
	cout<<endl;
	For(i,1,n){
		if(vis2[i])cout<<"Win ";
		else if(cnt[i]==b)cout<<"Lose ";
		else cout<<"Loop ";
	}
	cout<<endl;
	return 0;
}