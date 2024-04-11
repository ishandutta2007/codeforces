#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
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
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll tc,n,k,ans,nw,x[MAX],tmp;
vector<pll> v;

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>k;
    	nw = -1, v.clear();
    	rep(i,1,n)cin>>x[i];
    	if(k==1){cout<<(n&1)<<endl; continue;}
    	sort(x+1,x+1+n);
    	rap(i,n,1){
    		if(nw==-1)nw = x[i];
    		else if(nw==x[i])nw = -1;
    		else if(nw!=x[i]){
    			if(v.empty() || v.back().fi!=x[i])v.pb({x[i],1});
    			else {
    				while(1){
    					v[v.size()-1].se++;
    					if(v.back().se==k){
    						tmp = v.back().fi+1;
    						v.pob();
    						if(v.empty() || v.back().fi!=tmp){v.pb({tmp,1}); break;}
						}
						else break;
					}
					if(v[0].fi==nw)nw = -1, v.pob();
				}
			}
		}
		ans = (nw==-1 ? 0 : pw(k,nw));
		for(auto i:v)ans-= i.se * pw(k,i.fi);
		ans%= MOD;
		if(ans<0)ans+= MOD;
		cout<<ans<<endl;
	}
	return 0;
}