#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 320;

int tc,n,x,ans[MAX],k,p[MAX],sz[MAX],mx;
vector<int> v[MAX];
bool st[MAX];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

inline void merge(int a,int b){
	a = par(a), b = par(b);
	if(a!=b){
		p[a] = b;
		sz[b]+= sz[a];
	}
	return;
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("xot.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	rep(i,1,n)v[i].clear(), ans[i] = 0, p[i] = i, sz[i] = 1, st[i] = 0;
    	st[n+1] = 0;
    	rep(i,1,n)cin>>x, v[x].pb(i);
    	rap(i,n,1){
    		if(v[i].empty()){
    			ans[i] = n+1;
    			continue;
			}
			mx = 0;
			for(int j:v[i]){
				st[j] = 1;
				if(st[j-1])merge(j,j-1);
				if(st[j+1])merge(j,j+1);
				mx = max(mx,sz[par(j)]);
			}
			ans[i] = max(i,n-mx+1);
		}
		rep(i,2,n)ans[i] = max(ans[i-1],ans[i]);
		rap(i,n,1)cout<<(ans[i]==i);
		cout<<endl;
	}
    return 0;
}