// Phoenix

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
typedef long double ld;

const int maxn=(1<<20)+10;

ll m,p,a[maxn],b[maxn],c[40];
ll t;

ll Mul(ll a,ll b){
    return (a*b-(ll)((ld)a*b/p)*p)%p;
}

ll Pow(ll a,ll b){
    ll ans=1;
    while(b){
	if(b&1) ans=Mul(ans,a);
	a=Mul(a,a);
	b>>=1;	   
    }
    return ans;
}

void transform(ll *a,bool inv){
    int tw=1<<m;
    for(int ln=1;(2*ln)<=tw;ln*=2){
	for(int l=0;l<tw;l+=ln+ln){
	    for(int i=0;i<ln;i++){
		ll x=a[l+i],y=a[l+ln+i];
		a[l+i]=(x+y)%p;
		a[l+ln+i]=(x-y)%p;
	    }
	}
    }
    if(inv){
	for(int i=0;i<tw;i++){
	    if(a[i]<0) a[i]+=p;
	    a[i]>>=m;
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>m>>t>>p;
    p<<=m;
    for(int i=0;i<(1<<m);i++)
	cin>>a[i];
    for(int i=0;i<=m;i++)
	cin>>c[i];
    for(int i=0;i<(1<<m);i++)
	b[i]=c[__builtin_popcount(i)];
    transform(a,0);
    transform(b,0);
    for(int i=0;i<(1<<m);i++){
	a[i]=Mul(a[i],Pow(b[i],t));
    }
    transform(a,1);
    for(int i=0;i<(1<<m);i++){
	cout<<a[i]<<"\n";
    }
    return 0;
}