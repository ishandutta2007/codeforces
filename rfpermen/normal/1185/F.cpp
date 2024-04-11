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
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int n,m,k,f[1<<10],msk,mx,a,b,cs,pr,z,tmp,cnt;
pii p[1<<10],pz[MAX];
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n){
    	cin>>k;
    	msk = 0;
    	while(k--){
    		cin>>z;
    		msk|=(1<<(z-1));
		}
		++f[msk];
	}
	rep(i,0,1023)p[i].fi = MOD;
	rep(i,1,m){
    	cin>>pr>>k;
    	pz[i] = {pr,i};
    	msk = 0;
    	while(k--){
    		cin>>z;
    		msk|=(1<<(z-1));
		}
		if(pr<p[msk].fi)p[msk] = {pr,i};
	}
	sort(pz+1,pz+1+m);
	a = pz[1].se, b = pz[2].se;
	cs = pz[1].fi+pz[2].fi;
	rep(i,0,1023){
		if(p[i].fi==MOD)continue;
		tmp = 0;
		z = i;
		for(int k = z; k>0; k = (k-1)&z)tmp+=f[k];
		if(tmp>cnt){
			cnt = tmp;
			a = p[i].se;
			if(pz[1].se==a)b = pz[2].se, cs = pz[2].fi;
			else b = pz[1].se, cs = pz[1].fi;
			cs+=p[i].fi;
		}
		else if(tmp==cnt){
			tmp = p[i].fi;
			if(pz[1].se==p[i].se)tmp+= pz[2].fi;
			else tmp+= pz[1].fi;
			if(tmp<cs){
				cs = tmp;
				a = p[i].se;
				if(pz[1].se==a)b = pz[2].se;
				else b = pz[1].se;
			}
		}
	}
	rep(i,0,1023){
		if(p[i].fi==MOD)continue;
		rep(j,i+1,1023){
			if(p[j].fi==MOD)continue;
			tmp = 0;
			z = i|j;
			for(int k = z; k>0; k = (k-1)&z)tmp+=f[k];
			if(tmp>cnt||(tmp==cnt&&p[i].fi+p[j].fi<cs)){
				cnt = tmp;
				a = p[i].se;
				b = p[j].se;
				cs = p[i].fi+p[j].fi;
			}
		}
	}
	cout<<a<<' '<<b<<endl;
	return 0;
}