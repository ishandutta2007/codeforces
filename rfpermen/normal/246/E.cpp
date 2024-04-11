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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
//const int block = 2000;

int n,q,id,p,x[MAX],st[MAX],hs[MAX],en[MAX],dep[MAX],ans[MAX],k,u,mx,block,le,ri,cnt[MAX],res;
string s;
map<string,int> m;
bool vis[MAX];
vector<int> v[MAX],lis[MAX];
vector<piii> que[MAX];

void dfs(int nw){
	st[nw] = ++id;
	hs[id] = nw;
	for(auto i:v[nw]){
		dep[i] = dep[nw]+1;
		dfs(i);
		lis[dep[i]].pb(st[i]);
	}
	en[nw] = id;
	return;
}

inline bool cmp(piii a,piii b){
	if(a.sf/block==b.sf/block)return a.ss<b.ss;
	return a.sf<b.sf;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>s>>p;
    	if(!m[s])m[s] = ++id;
    	x[i] = m[s];
    	v[p].pb(i);
	}
	id = -1;
	dfs(0);
	cin>>q;
	rep(i,1,q){
		cin>>u>>k;
		if(dep[u]+k>n)continue;
		que[dep[u]+k].pb({i,{st[u],en[u]}});
	}
	rep(i,2,n){
		if(lis[i].empty()||que[i].empty())continue;
		block = sqrt(lis[i].size());
		for(int j = 0; j<que[i].size(); ++j){
			if(que[i][j].sf>lis[i].back()){que[i][j].sf = -1;}
			else {
				que[i][j].sf = lower_bound(all(lis[i]),que[i][j].sf) - lis[i].begin();
				que[i][j].ss = upper_bound(all(lis[i]),que[i][j].ss) - lis[i].begin() - 1;
				if(que[i][j].sf>que[i][j].ss)que[i][j].sf = -1;
			}
		}
		for(int j = 0; j<lis[i].size(); ++j)lis[i][j] = x[hs[lis[i][j]]];
		sort(all(que[i]),cmp);
		le = 0, ri = -1;
		for(auto j:que[i]){
			if(j.sf==-1)continue;
			while(ri<j.ss){
				++ri;
				if(!cnt[lis[i][ri]])++res;
				++cnt[lis[i][ri]];
			}
			while(le>j.sf){
				--le;
				if(!cnt[lis[i][le]])++res;
				++cnt[lis[i][le]];
			}
			while(ri>j.ss){
				--cnt[lis[i][ri]];
				if(!cnt[lis[i][ri]])--res;
				--ri;
			}
			while(le<j.sf){
				--cnt[lis[i][le]];
				if(!cnt[lis[i][le]])--res;
				++le;
			}
			ans[j.fi] = res;
		}
		rep(j,le,ri)--cnt[lis[i][j]];
		res = 0;
	}
	rep(i,1,q)cout<<ans[i]<<endl;
	return 0;
}