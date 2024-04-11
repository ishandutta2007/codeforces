// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll maxn=1e5+10,mod=1e9+7,Big=1e18;

pll p[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll x1,Y1,x2,y2,X,Y;cin>>x1>>Y1>>x2>>y2;
    X=x2-x1;Y=y2-Y1;
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n;i++){
	int xx,yy;
	if(s[i]=='U') xx=0,yy=1;
	if(s[i]=='D') xx=0,yy=-1;
	if(s[i]=='R') xx=1,yy=0;
	if(s[i]=='L') xx=-1,yy=0;
	p[i+1]={p[i].F+xx,p[i].S+yy};
    }
    ll l=0,r=Big,ans=Big;
    while(l<=r){
	ll mid=(l+r)>>1;
	ll cnt=mid/n,cnt2=mid%n;
	ll xx=cnt*p[n].F,yy=cnt*p[n].S;
	xx+=p[cnt2].F,yy+=p[cnt2].S;
	if(abs(xx-X)+abs(yy-Y)<=mid)
	    ans=mid,r=mid-1;
	else
	    l=mid+1;
    }
    if(ans==Big) ans=-1;
    return cout<<ans<<endl,0;
}