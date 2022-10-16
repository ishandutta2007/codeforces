#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define hp se.fi
#define dmg se.se
const ll MAX=200005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,a,b,tx,t,ans,sum;
pair<ll,pll> x[MAX];

int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b; b=min(b,n); tx=1; rep(i,1,a)tx*=2;
    rep(i,1,n)cin>>x[i].hp>>x[i].dmg, x[i].fi=min((ll)0,x[i].dmg-x[i].hp), sum+=x[i].dmg;
    if(!b){
    	cout<<sum<<endl;
    	return 0;
	}
    sort(x+1,x+1+n); rep(i,1,n)x[i].fi*=-1;
    rep(i,1,b)t+=x[i].fi;
    rep(i,1,b)ans=max(ans, t - x[i].fi + x[i].hp*tx - x[i].dmg);
    rep(i,b+1,n)ans=max(ans, t - x[b].fi + x[i].hp*tx - x[i].dmg);
    cout<<sum+ans<<endl;
    return 0;
}