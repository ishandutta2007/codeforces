#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 2505;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e15;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,bt,k,id,en,z,fc[20],dv[20],cs[MAX2],dp[MAX2][1<<11][11],cv[MAX],nw,ans,tmp,vis[MAX];
pll x[MAX];
map<ll,ll> hs;
vector<int> isi[MAX],v[MAX2],sos[1<<11],res;

void gen(int pos,ll x,int mask){
	if(x<=bt){
		vis[mask] = nw;
		return;
	}
	if(pos==k)return;
	gen(pos+1,x,mask);
	gen(pos+1,x/dv[pos],mask^(1<<pos));
	return;
}

bool cmp(int a,int b){
	if(x[a].fi==x[b].fi)return a<b;
	return x[a].fi<x[b].fi;
}

ll f(int nw,int mask,int rem){
	if(!mask)return 0;
	if(rem<0 || nw>id)return INF;
	ll &ret = dp[nw][mask][rem];
	if(ret!=-1)return ret;
	ret = f(nw+1,mask,rem)-cs[nw];
	for(int i:v[nw])ret = min(ret,f(nw+1,mask&i,rem-1));
	ret+= cs[nw];
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>bt;
    rep(i,1,n)cin>>x[i].se, z = __gcd(x[i].se,z);
    if(z==1)return cout<<"0\n",0;
    rep(i,1,n)cin>>x[i].fi;
    for(ll i = 2; i*i<=z; ++i)if(z%i==0){
    	fc[k++] = i, nw = 1;
    	while(z%i==0)z/=i, nw*=i;
//    	db(nw);
    	if(nw>bt)return cout<<"-1\n",0;
	}
	if(z!=1){
		fc[k++] = z;
//		db(z);
		if(z>bt)return cout<<"-1\n",0;
	}
	
    sort(x+1,x+1+n);
    rep(i,1,n){
    	nw = 1;
    	for(int j = 0; j<k; ++j){
    		while(x[i].se%fc[j]==0)nw*= fc[j], x[i].se/= fc[j];
		}
		if(!hs.count(nw))hs[nw] = ++id, cv[id] = nw;
		nw = hs[nw];
		if(isi[nw].size()!=k)isi[nw].pb(i);
	}
	
	en = (1<<k)-1;
//	db(en);
//	db(id);
	bool st;
	rep(i,1,id){
		nw = i;
		tmp = cv[i];
		for(int j = 0; j<k; ++j){
			dv[j] = 1;
			while(tmp%fc[j]==0)dv[j]*= fc[j], tmp/= fc[j];
//			cout<<"<> "<<fc[j]<<" -> "<<dv[j]<<endl;
		}
//		db(cv[i]);
		gen(0,cv[i],en);
		rep(o,1,en)if(vis[o]==i){
			st = 1;
			for(int j = 0; j<k; ++j)if((o&(1<<j))==0 && vis[o|(1<<j)]==i){
				st = 0;
				break;
			}
			if(st)for(int j:isi[i])sos[o].pb(j);
		}
	}
	rep(i,1,id)isi[i].clear();
	
	mems(vis,0);
	rap(i,en,1){
//		cout<<i<<" punya "<<sos[i].size()<<endl; 
		for(int j:sos[i])vis[j] = i;
		for(int j = 0; j<k; ++j)if((i&(1<<j))==0){
			tmp = i|(1<<j);
			for(int o:sos[tmp])sos[i].pb(o);
		}
		sort(all(sos[i]),cmp);
		res.clear();
		nw = 0;
		for(int j:sos[i])if(nw!=j){
			res.pb(j), nw = j;
			if(res.size()==k)break;
		}
		sos[i] = res;
		for(int j:res)if(vis[j]==i)isi[j].pb(~i);
	}
	
	id = 0;
	rep(i,1,n)if(!isi[i].empty()){
		cs[++id] = x[i].fi, v[id] = isi[i];
//		cout<<cs[id]<<" = ";
//		for(int j:v[id])cout<<(~j)<<' '; cout<<endl;
	}
	
	mems(dp,-1);
	ans = INF;
	rep(i,1,k){
//		db(f(1,en,i-1));
		ans = min(ans,f(1,en,i-1)*i);
	}
	cout<<(ans<1e12 ? ans : -1)<<endl;
	return 0;
}