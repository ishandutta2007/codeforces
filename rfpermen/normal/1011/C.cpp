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
#define w fi
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define pdi pair<double,int>
#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

ll n,ls;
double x,ans,le,ri,mid,nw,a[MAX],b[MAX],eps=1e-9;
bool st;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x;
    rep(i,1,n)cin>>a[i];
    cin>>b[n]; rep(i,2,n)cin>>b[i-1];
    ans = -1;
    le  = 0, ri = 1e12;
    rep(coba,1,100){
    	mid = (le+ri)/2;
    	nw = mid;
    	rep(i,1,n){
    		if(nw<0.0)break;
    		nw-=(x+nw)/a[i];
    		if(nw<0.0)break;
    		nw-=(x+nw)/b[i];
		}
		if(nw<0.0)le = mid;
		else ans = mid, ri = mid;
	}
	if(ans<-0.5)cout<<-1<<endl;
	else cout<<ans<<endl;
    return 0;
}