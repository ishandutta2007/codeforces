#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000000;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,m,a,b,par[MAX],k,x,dep[MAX],sp[MAX][18];
vector<int> v[MAX];
bool st;

void f(int nw){
	for(auto i:v[nw])if(i!=par[nw]){
		dep[i] = dep[nw]+1;
		par[i] = sp[i][0] = nw;
		f(i);
	}
}

inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	rap(i,17,0)if(dep[x]-(1<<i)>=dep[y])x = sp[x][i];
	if(x==y)return x;
	rap(i,17,0){
		if(sp[x][i]!=sp[y][i]){
			x = sp[x][i];
			y = sp[y][i];
		}
	}
	return sp[x][0];
}

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,2,n){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dep[1] = par[1] = 1;
	f(1);
	rep(i,1,17)rep(j,1,n)sp[j][i] = sp[sp[j][i-1]][i-1];
	int nw,ret;
	while(m--){
		cin>>k;
		cin>>x;
		nw = par[x];
		st = 1;
		rep(i,2,k){
			cin>>x;
			if(!st)continue;
			x = par[x];
			ret = lca(nw,x);
			if(ret==nw)nw = x;
			else if(ret!=x)st = 0;
		}
		cout<<(st?"YES":"NO")<<endl;
	}
	return 0;
}