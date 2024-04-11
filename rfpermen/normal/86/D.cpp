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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000004381;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int cnt[5*MAX];
ll n,q,x[MAX],ans[MAX],res,ls,le,ri;
piii y[MAX];

inline bool cmp(piii a,piii b){
	if(a.sf/block==b.sf/block)return a.ss<b.ss;
	return a.sf<b.sf;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("gift.in", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>x[i];
    rep(i,1,q)cin>>y[i].sf>>y[i].ss, y[i].fi = i;
    sort(y+1,y+1+q,cmp);
    ls = y[1].sf/block;
    rep(i,1,q){
    	if(y[i].sf/block!=ls){
    		ls = y[i].sf/block;
    		rep(j,le,ri)--cnt[x[j]];
    		res = 0;
    		le = y[i].sf, ri = y[i].ss;
    		rep(j,le,ri){
    			++cnt[x[j]];
    			res+=(2*cnt[x[j]]-1)*x[j];
			}
		}
		while(y[i].ss>ri)++ri, ++cnt[x[ri]], res+=(2*cnt[x[ri]]-1)*x[ri];
		while(y[i].sf>le)--cnt[x[le]], res-=(2*cnt[x[le]]+1)*x[le], ++le;
		while(y[i].sf<le)--le, ++cnt[x[le]], res+=(2*cnt[x[le]]-1)*x[le];
		ans[y[i].fi] = res;
	}
	rep(i,1,q)cout<<ans[i]<<endl;
	return 0;
}