#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
const int MAX = 1e6+5;
const ll MAX2 = 5e3+5;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll n,k,x[MAX],ans,le,lmn[MAX],rmn[MAX],lmx[MAX],rmx[MAX],y[MAX],z[MAX],Y[MAX],Z[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)cin>>x[i], lmn[i] = lmx[i] = rmn[i] = rmx[i] = x[i];
	lmn[0] = rmn[n+1] = 1e9;
    rap(i,n,1)rmn[i] = min(rmn[i],rmn[i+1]), rmx[i] = max(rmx[i],rmx[i+1]);
    rep(i,1,n)lmn[i] = min(lmn[i],lmn[i-1]), lmx[i] = max(lmx[i],lmx[i-1]);
    
    rep(i,1,k)z[i] = y[i] = 1e9;
    rep(i,1,n){
    	if(x[i]>rmn[i+1]){
	    	z[x[i]] = min(z[x[i]],rmn[i+1]);
	    	y[x[i]] = min(y[x[i]],rmn[i+1]);
		}
		if(x[i]<lmx[i-1]){
			Z[x[i]] = max(Z[x[i]],lmx[i-1]);
		}
	}
    rap(i,k-1,1)z[i] = min(z[i],z[i+1]), Z[i] = max(Z[i],Z[i+1]);
    rep(i,2,k)y[i] = min(y[i],y[i-1]);
    
//    rap(i,n,1)if(x[i]<lmx[i-1])y[x[i]] = max(y[x[i]],lmx[i-1]);
//    
//    rap(i,k-1,1)y[i] = max(y[i],y[i+1]);
    
	le = k;
	z[k+1] = y[0] = 1e9;
    rap(i,k,1){
    	if(Z[i+1]>i)break;
    	if(le>i)le = i;
    	while(le>0&&(z[i+1]<le||y[le-1]!=1e9))le--;
    	if(le==0)break;
    	ans+=le;
//    	cout<<le<<' '<<i<<endl;
	}
	cout<<ans<<endl;
	return 0;
}