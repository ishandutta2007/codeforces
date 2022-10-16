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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pdd pair<double,double> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

ll n,x,y,x2,y2,ans,a,b,mx;
plll z[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x>>y>>x2>>y2;
    rep(i,1,n){
    	cin>>z[i].sf>>z[i].ss;
    	a = abs(z[i].sf-x), b = abs(z[i].ss-y);
    	z[i].fi = a*a+b*b;
	}
	sort(z+1,z+1+n);
	ans = z[n].fi;
	rap(i,n,1){
		a = abs(z[i].sf-x2), b = abs(z[i].ss-y2);
		mx = max(mx,a*a+b*b);
		ans = min(z[i-1].fi+mx,ans);
	}
	cout<<ans<<endl;
    return 0;
}