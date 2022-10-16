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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,a[3],b,c,d,x,y,z,sz,sz2,T,ans;
string s,t;

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,0,2)cin>>a[i];
    sort(a,a+3);
    if(n%a[0]==0)return cout<<n/a[0],0;
    b = n/a[0];
    sz = n%a[0];
    while(sz<=n){
    	if(sz%a[1]==0)ans = max(b+sz/a[1],ans);
    	c = sz/a[1];
    	d = 0;
    	//cout<<"c "<<c<<endl;
    	rap(i,c,0){
    		sz2 = sz - i*a[1];
    		//cout<<sz2<<endl;
    		if(sz2-d*a[2]-a[2]>=0)d++;
    		//cout<<b<<" "<<i<<" "<<d<<endl;
    		if(b*a[0]+i*a[1]+d*a[2]==n)ans = max(ans,b+i+d);//, cout<<b<<" "<<c<<" "<<d<<endl
		}
    	sz+=a[0];
    	b--;
	}
	cout<<ans<<endl;
    return 0;
}