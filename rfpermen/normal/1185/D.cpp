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
 
ll n,m,b,ans;
pll x[MAX];
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i].fi, x[i].se = i;
    sort(x+1,x+1+n);
    b = x[2].fi-x[1].fi;
    rep(i,2,n){
    	if(x[i].fi-x[i-1].fi!=b){
    		if(ans){ans = -1; break;}
    		ans = x[i].se;
    		if(i!=n){
    			if(x[i+1].fi-x[i-1].fi!=b){ans = -1; break;}
    			i++;
			}
		}
	}
	if(ans!=-1){
		if(ans==0)ans = x[1].se;
		return cout<<ans<<endl,0;
	}
	b = x[3].fi-x[1].fi;
	ans = x[2].se;
	rep(i,4,n)if(x[i].fi-x[i-1].fi!=b){ans = -1; break;}
	if(ans!=-1)return cout<<ans<<endl,0;
	
	b = x[3].fi-x[2].fi;
	ans = x[1].se;
	rep(i,3,n)if(x[i].fi-x[i-1].fi!=b){ans = -1; break;}
	cout<<ans<<endl;
	return 0;
}