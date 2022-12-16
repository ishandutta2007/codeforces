// only miss the sun when it starts to snow

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
typedef unsigned int ui;

const int maxn=1e5+10, Max=8e7 +10;

bitset<80000100> bs;
ui n,a,b,c,d,ans;
ui md[8]={1,7,11,13,17,19,23,29};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    cin>>n>>a>>b>>c>>d;

    ui p=2,tmp=n,cnt=0;
    while(tmp>0) tmp/=p, cnt+=tmp;
    ans+=cnt* (p*p*p*a + p*p*b + p*c + d);

    p=3,tmp=n,cnt=0;
    while(tmp>0) tmp/=p, cnt+=tmp;
    ans+=cnt* (p*p*p*a + p*p*b + p*c + d);

    p=5,tmp=n,cnt=0;
    while(tmp>0) tmp/=p, cnt+=tmp;
    ans+=cnt* (p*p*p*a + p*p*b + p*c + d);

    ui lim=sqrt(n) + 3;
    
    bs[0]=1;
    for(ui i=0; i<Max; i++){
	ui x=30* (i/8) + md[i%8];
	if(x>n) continue;
	if(bs[i]==0){
	    p=x,tmp=n,cnt=0;
	    while(tmp>0) tmp/=p, cnt+=tmp;
	    ans+=cnt* (p*p*p*a + p*p*b + p*c + d);
	    
	    if(x<=lim){
		for(ui y=x*x; y<=n; y+=x){
		    ui dv=y/30, rem= y%30;
		    if(rem==1)  bs[(dv<<3)   ]=1;
		    else if(rem==7)  bs[(dv<<3) +1]=1;
		    else if(rem==11) bs[(dv<<3) +2]=1;
		    else if(rem==13) bs[(dv<<3) +3]=1;
		    else if(rem==17) bs[(dv<<3) +4]=1;
		    else if(rem==19) bs[(dv<<3) +5]=1;
		    else if(rem==23) bs[(dv<<3) +6]=1;
		    else if(rem==29) bs[(dv<<3) +7]=1;
		}
	    }
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")