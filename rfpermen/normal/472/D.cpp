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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,N,x[MAX][MAX],y[MAX][MAX],id,p[MAX],a,b,cnt;
piii e[MAX*MAX];
vector<pii> v[MAX];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

void dfs(int r,int c){
	for(auto i:v[c]){
		if(y[r][i.fi]!=-1)continue;
		y[r][i.fi] = y[r][c]+i.se;
		dfs(r,i.fi);
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)rep(j,1,n)cin>>x[i][j], e[++id] = {x[i][j],{i,j}};
    rep(i,1,n){
    	p[i] = i;
    	if(x[i][i])return cout<<"NO\n",0;
    	rep(j,i+1,n)if(x[i][j]!=x[j][i]||x[i][j]==0)return cout<<"NO\n",0;
	}
	N = n*n;
	sort(e+1,e+1+N);
	rep(i,n+1,N){
		a = par(e[i].sf), b = par(e[i].ss);
		if(a==b)continue;
		p[a] = b;
		v[e[i].sf].pb({e[i].ss,e[i].fi});
		v[e[i].ss].pb({e[i].sf,e[i].fi});
		++cnt;
		if(cnt==n-1)break;
	}
	memset(y,-1,sizeof y);
	rep(i,1,n)y[i][i] = 0, dfs(i,i);
	rep(i,1,n)rep(j,1,n)if(x[i][j]!=y[i][j])return cout<<"NO\n",0;
	cout<<"YES\n";
	return 0;
}