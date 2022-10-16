#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,x[MAX],y[MAX],q,id,ans[MAX],bit[MAX],ls[MAX],tmp[MAX],nw;
piii qu[MAX];
map<int,int> hs;

inline void upd(int i,int val){
	for(;i<=n;i+=i&-i)bit[i]^= val;
	return;
}
int ret;
inline int que(int i){
	ret = 0;
	for(;i>0;i-=i&-i)ret^= bit[i];
	return ret;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x[i];
    	y[i] = y[i-1]^x[i];
    	if(!hs.count(x[i]))hs[x[i]] = ++id, tmp[id] = i;
    	else {
    		q = hs[x[i]];
    		ls[i] = tmp[q];
    		tmp[q] = i;
		}
	}
	cin>>q;
	rep(i,1,q)cin>>qu[i].sf>>qu[i].fi, qu[i].ss = i;
	sort(qu+1,qu+1+q);
	nw = 1;
	rep(i,1,q){
		while(nw<=n && nw<=qu[i].fi){
			if(ls[nw])upd(ls[nw],x[nw]);
			upd(nw,x[nw]);
			++nw;
		}
		ans[qu[i].ss] = y[qu[i].fi]^y[qu[i].sf-1]^que(qu[i].fi)^que(qu[i].sf-1);
	}
	rep(i,1,q)cout<<ans[i]<<endl;
    return 0;
}