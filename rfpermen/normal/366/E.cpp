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
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 4e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int n,m,k,q,a,b,x[MAX][MAX],ans,sz;
bool st[10][10];
vector<pii> v[10];

inline bool f(int a,int b,int k){
	int x1 = max(1,a-k)-1, x2 = min(n,a+k), y1 = max(1,b-k)-1, y2 = min(m,b+k);
	return x[x2][y2] - x[x1][y2] - x[x2][y1] + x[x1][y1] != sz;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>q;
    rep(i,1,n)rep(j,1,m)cin>>a, v[a].pb({i+j,i-j+m});
    n+=m, m = n;
    cin>>a;
    rep(i,2,q){
    	cin>>b;
    	if(a<=b)st[a][b] = 1;
    	else st[b][a] = 1;
    	a = b;
	}
	rep(cl,1,k)if(v[cl].size()){
		mems(x,0);
		for(pii i:v[cl])x[i.fi][i.se] = 1;
		rep(i,1,n)rep(j,1,m)x[i][j]+= x[i-1][j] + x[i][j-1] - x[i-1][j-1];
		sz = v[cl].size();
		rep(o,cl,k)if(st[cl][o])for(pii i:v[o])while(f(i.fi,i.se,ans))++ans;
	}
	cout<<ans<<endl;
    return 0;
}