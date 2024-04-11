#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,bit[MAX],y[MAX],z[MAX],a,val,ans[MAX],mx,id;
vector<int> v[MAX],nw,nx;
set<int> dat;
pii x[MAX];

inline void upd(int i){
	for(; i<=n; i+=(i&-i))bit[i] = max(bit[i],val);
}
int ret;
inline int que(int i){
	ret = 0;
	for(; i>0; i-=(i&-i))ret = max(bit[i],ret);
	return ret;
}

inline bool cmp(int a,int b){
	return y[a]>y[b];
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>y[i], x[i] = {y[i],-i};
    sort(x+1,x+1+n);
    rep(i,1,n){
    	a = -x[i].se;
    	val = que(a)+1;
    	upd(a);
    	z[a] = val;
	}
	rep(i,1,n)v[z[i]].pb(i), mx = max(mx,z[i]);
	
	for(auto i:v[mx])ans[i] = 2, nw.pb(i);
	if(v[mx].size()==1)ans[v[mx][0]] = 3;
	sort(all(nw),cmp);
	
	auto it = dat.begin();
	rap(i,mx-1,1){
		sort(all(v[i]),cmp);
		dat.clear(), nx.clear();
		id = 0;
		for(auto k:v[i]){
			while(id<nw.size() && y[nw[id]]>y[k])dat.insert(nw[id]), ++id;
			it = dat.lower_bound(k);
			if(it==dat.end())ans[k] = 1;
			else nx.pb(k);
		}
		if(nx.size()==1)ans[nx[0]] = 3;
		else for(auto k:nx)ans[k] = 2;
		nw = nx;
	}
	rep(i,1,n)cout<<ans[i]; cout<<endl;
    return 0;
}