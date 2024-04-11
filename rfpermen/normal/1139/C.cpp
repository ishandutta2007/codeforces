#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pdd pair<double,double> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,k,a,b,p[MAX],sz[MAX],c;
ll ans;
int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}
ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = (ret*x)%MOD;
		x = (x*x)%MOD;
		y>>=1;
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)p[i] = i, sz[i] = 1;
    rep(i,2,n){
    	cin>>a>>b>>c;
    	if(!c){
    		a = par(a), b = par(b);
    		p[a] = b;
    		sz[b]+=sz[a];
    		sz[a] = 0;
		}
	}
	rep(i,1,n)ans-=pw(sz[i],k);
	cout<<(ans%MOD+pw(n,k)+MOD)%MOD<<endl;
    return 0;
}