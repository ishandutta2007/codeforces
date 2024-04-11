#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,x[MAX],mn,id;
set<int> s;
ll ans;

struct trie{
	int nx[2];
}tr[6000000];

inline void ins(int x){
	int nw = 0;
	bool st;
	rap(i,29,0){
		st = (x&(1<<i))!=0;
		if(!tr[nw].nx[st])tr[nw].nx[st] = ++id;
		nw = tr[nw].nx[st];
	}
	return;
}

int f(int lvl,int a,int b){
	if(!lvl)return 0;
	bool ad = 0;
	int ret = INT_MAX;
	if(tr[a].nx[0]&&tr[b].nx[0])ret = f(lvl-1,tr[a].nx[0],tr[b].nx[0]), ad = 1;
	if(tr[a].nx[1]&&tr[b].nx[1])ret = min(f(lvl-1,tr[a].nx[1],tr[b].nx[1]),ret), ad = 1;
	if(!ad){
		if(tr[a].nx[0]&&tr[b].nx[1])ret = f(lvl-1,tr[a].nx[0],tr[b].nx[1]);
		if(tr[a].nx[1]&&tr[b].nx[0])ret = min(f(lvl-1,tr[a].nx[1],tr[b].nx[0]),ret);
		ret|= (1<<lvl-1);
	}
	return ret;
}

void dfs(int lvl,int nw){
	if(tr[nw].nx[0]&&tr[nw].nx[1])ans+= (1<<lvl-1) + f(lvl-1,tr[nw].nx[0],tr[nw].nx[1]);
	if(lvl==1)return;
//	cout<<lvl<<' '<<tr[nw].nx[0]<<endl;
	if(tr[nw].nx[0])dfs(lvl-1,tr[nw].nx[0]);
	if(tr[nw].nx[1])dfs(lvl-1,tr[nw].nx[1]);
	return;
}

int main(){
//	cout<<fixed<<setprecision(5);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>mn, s.insert(mn);
    n = 0;
    for(auto i:s)x[++n] = i;
    rep(i,1,n)ins(x[i]);
    dfs(30,0);
    cout<<ans<<endl;
	return 0;
}