// Can U hack it?

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

const int mod=998244353,maxn=510;

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

pair<bool,ll> t4(ll x){
    ll l=1,r=37607,ans=0;
    while(l<=r){
	ll mid=(l+r)/2;
	if((mid*mid*mid*mid)<=x){
	    l=mid+1;
	    ans=mid;
	}
	else{
	    r=mid-1;
	}
    }
    return {(ans*ans*ans*ans == x),ans};
}

pair<bool,ll> t3(ll x){
    ll l=1,r=2000000,ans=0;
    while(l<=r){
	ll mid=(l+r)/2;
	if((mid*mid*mid)<=x){
	    l=mid+1;
	    ans=mid;
	}
	else{
	    r=mid-1;
	}
    }
    return {(ans*ans*ans == x),ans};
}
pair<bool,ll> t2(ll x){
    ll l=1,r=2000000000,ans=0;
    while(l<=r){
	ll mid=(l+r)/2;
	if((mid*mid)<=x){
	    l=mid+1;
	    ans=mid;
	}
	else{
	    r=mid-1;
	}
    }
    return {(ans*ans == x),ans};
}

map<ll,ll>mp;
map<ll,ll>cnt;
ll a[maxn];

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
	scanf("%lld",&a[i]);
	pair<bool,ll> p4=t4(a[i]),p3=t3(a[i]),p2=t2(a[i]);
	if(p4.F) mp[p4.S]+=4;
	else if(p3.F) mp[p3.S]+=3;
	else if(p2.F) mp[p2.S]+=2;
	else cnt[a[i]]++;
    }
    ll ans=1;
    for(auto p:cnt){
	bool IS=0;
	for(int i=0;i<n;i++){
	    if(a[i]==p.F)continue;
	    ll x=gcd(p.F,a[i]);
	    if(x!=1){
		mp[p.F/x]+=p.S;
		mp[x]+=p.S;
		IS=1;
		break;
	    }
	}
	if(!IS) ans=ans*(p.S+1) %mod *(p.S+1) %mod;
    }
    for(auto p:mp)
	ans=(ans*(p.S+1))%mod;
    printf("%lld\n",ans);
}