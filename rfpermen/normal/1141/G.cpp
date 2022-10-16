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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,k,ans[MAX],a,b,vis[MAX],nw,id;
pii cnt[MAX];
vector<pii> v[MAX];
bool st[MAX];

void dfs(int nw,int par){
	if(!st[nw]){
		for(auto i:v[nw])vis[ans[i.se]] = nw;
		id = 0;
		for(auto i:v[nw]){
			if(!ans[i.se]){
				while(vis[++id]==nw);
				ans[i.se] = id;
			}
		}
	}
	for(auto i:v[nw])if(i.fi!=par)dfs(i.fi,nw);
	return;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb({b,i}), v[b].pb({a,i});
	}
    rep(i,1,n)cnt[i] = {v[i].size(),i};
    sort(cnt+1,cnt+1+n), reverse(cnt+1,cnt+1+n);
    rep(i,1,k)st[cnt[i].se] = 1;
    dfs(cnt[k+1].se,0);
    cout<<cnt[k+1].fi<<endl;
    rep(i,2,n)cout<<(ans[i] ? ans[i] : 1)<<' '; cout<<endl;
    return 0;
}