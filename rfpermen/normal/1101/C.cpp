#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
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
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=998244353;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int tc,n,id,mx,ans[MAX],nw;
pii x[MAX],y[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    x[0] = {1e9,0};
    rep(k,1,tc){
    	cin>>n;
    	rep(i,1,n)cin>>x[i].fi>>x[i].se, y[i] = {x[i].fi,i};
    	sort(y+1,y+1+n);
    	y[0].se = y[n+1].se = mx = 0, id = 1;
    	rep(i,1,n){
    		if(x[y[i].se].fi>max(x[y[i-1].se].se,mx)){
    			rap(j,i-1,id)ans[y[j].se] = nw+1;
    			nw^=1, id = i;
			}
    		mx = max(mx,x[y[i].se].se);
		}
    	if(id==1)cout<<"-1\n";
    	else {
    		rap(j,n,id)ans[y[j].se] = nw+1;
    		rep(i,1,n)cout<<ans[i]<<' ';
			cout<<endl;
		}
	}
    return 0;
}