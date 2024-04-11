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
//#define ff fi.fi
//#define fs fi.se
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
const int MAX = 5e3+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const long double EPS = 1e-18;
const int block = 2000;

int n,m,vis[105];
pii x[105];
vector<int> v[105];

void dfs(int nw){
	for(int i:v[nw]){
		if(vis[i]==-1)vis[i] = vis[nw]^1, dfs(i);
		if(vis[i]!=vis[nw]^1){
			cout<<"Impossible\n";
			exit(0);
		}
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    cin>>n>>m;
    rep(i,1,m){
    	cin>>x[i].fi>>x[i].se;
    	if(x[i].fi>x[i].se)swap(x[i].fi,x[i].se);
	}
	rep(i,1,m)rep(j,i+1,m){
		if((x[i].fi<x[j].fi&&x[i].se>x[j].fi&&x[i].se<x[j].se) ||
			(x[j].fi<x[i].fi&&x[j].se>x[i].fi&&x[j].se<x[i].se))v[i].pb(j), v[j].pb(i);
	}
	memset(vis,-1,sizeof vis);
	rep(i,1,m){
		if(vis[i]!=-1)continue;
		vis[i] = 0;
		dfs(i);
	}
	rep(i,1,m)cout<<(vis[i] ? 'i' : 'o');
    return 0;
}