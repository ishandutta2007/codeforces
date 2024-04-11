#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll tc,n,x[MAX],ans,mx,z;
vector<int> res;
set<int> vv;
bool st;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n;
    	vv.clear();
    	while(n--){
    		cin>>z;
    		vv.insert(z);
		}
		n = 0;
		for(auto i:vv)x[++n] = i;
    	sort(x+1,x+1+n);
    	reverse(x+1,x+1+n);
    	mx = 0;
    	ans = x[1];
    	res.clear();
    	res.pb(x[1]);
    	rep(i,2,n){
    		if(res.size()==3)break;
    		st = 1;
    		for(auto j:res)if(j%x[i]==0){
    			st = 0; break;
			}
			if(st)ans+=x[i], res.pb(x[i]);
		}
		mx = max(mx,ans);
		if(n>=2){
	    	ans = x[2];
	    	res.clear();
	    	res.pb(x[2]);
	    	rep(i,3,n){
	    		if(res.size()==3)break;
	    		st = 1;
	    		for(auto j:res)if(j%x[i]==0){
	    			st = 0; break;
				}
				if(st)ans+=x[i], res.pb(x[i]);
			}
			mx = max(mx,ans);
		}
		if(n>=3){
	    	ans = x[3];
	    	res.clear();
	    	res.pb(x[3]);
	    	rep(i,4,n){
	    		if(res.size()==3)break;
	    		st = 1;
	    		for(auto j:res)if(j%x[i]==0){
	    			st = 0; break;
				}
				if(st)ans+=x[i], res.pb(x[i]);
			}
			mx = max(mx,ans);
		}
		if(n>=4){
	    	ans = x[4];
	    	res.clear();
	    	res.pb(x[4]);
	    	rep(i,5,n){
	    		if(res.size()==3)break;
	    		st = 1;
	    		for(auto j:res)if(j%x[i]==0){
	    			st = 0; break;
				}
				if(st)ans+=x[i], res.pb(x[i]);
			}
			mx = max(mx,ans);
		}
		if(n>=5){
	    	ans = x[5];
	    	res.clear();
	    	res.pb(x[5]);
	    	rep(i,6,n){
	    		if(res.size()==3)break;
	    		st = 1;
	    		for(auto j:res)if(j%x[i]==0){
	    			st = 0; break;
				}
				if(st)ans+=x[i], res.pb(x[i]);
			}
			mx = max(mx,ans);
		}
		cout<<mx<<endl;
	}
	return 0;
}