#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
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
#define pii pair<int,int> 
#define pll pair<int,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,m,fact[MAX],tw[MAX],ret,cnt,ans,y;
bool x[MAX];

ll pw(ll x,ll y){
	ret = 1;
	while(y){
		if(y&1)ret = (ret*x)%MOD;
		x = (x*x)%MOD;
		y>>=1;
	}
	return ret;
}

int main(){
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fact[0] = 1; rep(i,1,1000)fact[i] = (fact[i-1]*i)%MOD;
    tw[1] = 1; rep(i,2,1000)tw[i] = (tw[i-1]*2)%MOD;
    cin>>n>>m;
    rep(i,1,m)cin>>y, x[y] = 1;
    cnt = n-m;
    ans = fact[cnt];
    cnt = 0;
    rep(i,1,n){
    	if(x[i])ans = (ans*pw(fact[cnt],MOD-2))%MOD, cnt = 0;
    	else cnt++;
	}
	ans = (ans*pw(fact[cnt],MOD-2))%MOD, cnt = 0;
	rep(i,1,n){
		if(x[i]){
			if(cnt!=i-1 && cnt)ans = (ans*tw[cnt])%MOD;
			cnt = 0;
		}
		else cnt++;
	}
	cout<<ans<<endl;
    return 0;
}