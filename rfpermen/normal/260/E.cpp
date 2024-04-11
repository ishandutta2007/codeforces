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
const int MAX = 4e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,idx,idy,cvx[MAX],cvy[MAX],id,cnt[MAX],bit[MAX],k,tmp,res,stx[MAX],sty[MAX],a,b,c,d;
piiii cnd[MAX];
pii x[MAX];
map<int,int> hsx,hsy;
vector<int> v,up[MAX];
vector<piiii> qu[MAX];

inline void upd(int i){
	for(;i<=idy;i+=i&-i)++bit[i];
	return;
}
int ret;
inline int que(int i){
	ret = 0;
	for(;i>0;i-=i&-i)ret+= bit[i];
	return ret;
}

int main(){
 cout<<fixed<<setprecision(2);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i].fi>>x[i].se, hsx[x[i].fi], hsy[x[i].se];
    for(auto i:hsx)hsx[i.fi] = ++idx, cvx[idx] = i.fi;
    for(auto i:hsy)hsy[i.fi] = ++idy, cvy[idy] = i.fi;
    rep(i,1,n){
    	x[i] = {hsx[x[i].fi],hsy[x[i].se]};
    	++cnt[x[i].fi];
    	up[x[i].fi].pb(x[i].se);
	}
	rep(i,1,idx)cnt[i]+= cnt[i-1], stx[cnt[i]] = i;
	mems(cnt,0);
	rep(i,1,n)++cnt[x[i].se];
	rep(i,1,idy)cnt[i]+= cnt[i-1], sty[cnt[i]] = i;
	mems(cnt,0);
	
    rep(i,1,9)cin>>k, v.pb(k);
    sort(all(v));
    do{
    	a = v[0]+v[3]+v[6];
    	if(!stx[a])continue;
    	b=a+v[1]+v[4]+v[7];
    	if(!stx[b])continue;
    	
    	c = v[0]+v[1]+v[2];
    	if(!sty[c])continue;
    	d=c+v[3]+v[4]+v[5];
    	if(!sty[d])continue;
    	
    	a = stx[a], b = stx[b], c = sty[c], d = sty[d];
    	++id;
    	qu[a].pb({{id,v[0]},{0,c}});
    	qu[a].pb({{id,v[3]},{c,d}});
    	
    	qu[b].pb({{id,v[0]+v[1]},{0,c}});
    	qu[b].pb({{id,v[3]+v[4]},{c,d}});
    	cnd[id] = {{a,b},{c,d}};
	}while(next_permutation(all(v)));
	
	rep(i,1,idx){
		for(int j:up[i])upd(j);
		
		for(piiii j:qu[i])if(que(j.ss)-que(j.sf)==j.fs){
			++cnt[j.ff];
			if(cnt[j.ff]==4){
				k = j.ff;
				cout<<cvx[cnd[k].ff]+0.69<<' '<<cvx[cnd[k].fs]+0.69<<endl;
				cout<<cvy[cnd[k].sf]+0.69<<' '<<cvy[cnd[k].ss]+0.69<<endl;
				return 0;
			}
		}
	}
	cout<<"-1\n";
    return 0;
}