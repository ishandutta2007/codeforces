#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define ff fi.fi
#define fs fi.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<ll,pll>
#define pdd pair<double,double>
#define endl "\n"
#define usi unsigned short int
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

ll n,x[MAX],y[MAX],st,cnt;

int main(){
	cout<<fixed<<setprecision(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    st = 1;
    cin>>x[1];
    rep(i,2,n){
    	cin>>x[i];
    	if(x[i-1]>x[i])st=i;
	}
	rep(i,st,n)y[++cnt] = x[i];
	rep(i,1,st-1)y[++cnt] = x[i];
	rep(i,2,n)if(y[i]<y[i-1])return cout<<-1,0;
	if(st==1)cout<<0;
	else cout<<n-st+1;
    return 0;
}