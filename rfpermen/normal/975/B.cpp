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
const ll MAX=100010;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll x[15],y[15],mx,cnt,nw,rel,n;

int main(){
    //cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    n=14;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n){
    	rep(j,1,n)y[j]=x[j];
    	nw=x[i];y[i]=0;rel=nw/n;
    	//rep(j,1,n)cout<<y[j]<<" ";cout<<endl;
    	rep(j,i+1,n+i){
    		if(j%n==0){
    			y[n]+=rel;
    			if(nw%n!=0)y[n]++, nw--;
			}
			else {
				y[j%n]+=rel;
    			if(nw%n!=0)y[j%n]++, nw--;
    			//cout<<nw<<endl;
			}
			//cout<<j%14<<endl;
			//cout<<nw<<" "<<rel<<endl;
		}
		cnt=0;
		//rep(j,1,n)cout<<y[j]<<" ";cout<<endl;
		rep(j,1,n){
			if(y[j]%2==0)cnt+=y[j];
		}
		mx=max(cnt,mx);
	}
	cout<<mx<<endl;
    return 0;
}