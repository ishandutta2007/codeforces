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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,p[MAX],x[MAX],id,ans[MAX];
vector<int> v[MAX];

void upd(int nw){
	ans[nw] = ++id;
	vector<int> z;
	while(p[nw])nw = p[nw], z.pb(nw), --x[nw];
	while(!z.empty()){
		nw = z.back(), z.pob();
		if(!x[nw])upd(nw);
	}
	return;
}

void dfs(int nw){
	if(!x[nw])upd(nw);
	for(auto i:v[nw])dfs(i);
	if(!ans[nw])cout<<"NO\n", exit(0);
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>p[i]>>x[i], v[p[i]].pb(i);
    dfs(v[0][0]);
    cout<<"YES\n";
    rep(i,1,n)cout<<ans[i]<<' '; cout<<endl;
    return 0;
}