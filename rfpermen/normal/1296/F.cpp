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
const int MAX = 5e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,q,a,b,x,ans[MAX],id;
bool st;
pii bt[MAX][MAX];
piii z[MAX];
vector<pii> v[MAX];

void dfs(int nw,int par){
	for(auto i:v[nw])if(i.fi!=par){
		bt[id][i.fi] = {nw,i.se};
		dfs(i.fi,nw);
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	ans[i] = 1;
    	v[a].pb({b,i});
    	v[b].pb({a,i});
	}
	rep(i,1,n)id = i, dfs(i,0);
	cin>>q;
	rep(i,1,q){
		cin>>a>>b>>x;
		z[i] = {a,{b,x}};
		while(a!=b){
			ans[bt[b][a].se] = max(ans[bt[b][a].se],x);
			a = bt[b][a].fi;
		}
	}
	rep(i,1,q){
		a = z[i].fi, b = z[i].sf, x = z[i].ss;
		st = 0;
		while(a!=b){
			if(ans[bt[b][a].se]==x){st = 1; break;}
			a = bt[b][a].fi;
		}
		if(!st)return cout<<"-1\n",0;
	}
	rep(i,2,n)cout<<ans[i]<<' '; cout<<endl;
    return 0;
}