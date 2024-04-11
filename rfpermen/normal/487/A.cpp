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
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pll>
#define endl "\n"
const ll MAX=2e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,1,0,-1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int a,b,c,x,y,z,p,q,r,ans,t1,t2;
bool st;

int main(){
    cout<<fixed<<setprecision(9);
    //freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>c;
    cin>>x>>y>>z;
    cin>>p>>q>>r;
    ans = 1e9;
    rep(h,0,1000)rep(t,0,1000)rep(d,0,1000){
    	if(z>=b+t)continue;
    	t1 = (x+b+t-z-1)/(b+t-z);
    	if(c+d>=y){
    		ans = min(ans,h*p+t*q+d*r); break;
		}
		t2 = (a+h+y-c-d-1)/(y-c-d);
		if(t1<t2){
//			if(h==1)cout<<h<<" "<<t<<" "<<d<<endl;
			ans = min(ans,h*p+t*q+d*r); break;
		}
	}
	cout<<ans<<endl;
    return 0;
}