// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e9;

ll n,m,x,y;
int vx,vy;
bool rx,ry;
ll lc;

void ANS(ll a,ll b){
    if(a==-1){
	printf("%d\n",-1);
    }
    else{
	if(rx) a=n-a;
	if(ry) b=m-b;
	printf("%lld %lld\n",a,b);
    }
    exit(0);
}

ll zarb(ll a,ll b){
    if(b<0) b=-b,a=-a;
    ll ans=0;
    while(b>0){
	if(b&1) ans=(ans+a)%lc;
	a=(a+a)%lc;
	b/=2;
    }
    return ans;
}

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

pll GCD(ll a,ll b){
    if(b==0)return {1,0};
    pll p=GCD(b,a%b);
    return {-p.S,(-p.F-zarb(p.S,(a/b)))%lc};
}

int main(){
    scanf("%lld%lld%lld%lld%d%d",&n,&m,&x,&y,&vx,&vy);
    if(vx==0){
	if(x!=0 && x!=n)
	    ANS(-1,-1);
	if(vy==1)
	    ANS(x,m);
	else
	    ANS(x,0);
    }
    if(vy==0){
	if(y!=0 && y!=m)
	    ANS(-1,-1);
	if(vx==1)
	    ANS(n,y);
	else
	    ANS(0,y);
    }
    if(vx==-1)
	rx=1,x=n-x;
    if(vy==-1)
	ry=1,y=m-y;

    ll g=gcd(m,n);
    lc=(m/g)*n;
    pll p=GCD(m,n);

    if((y-x)%g!=0)
	ANS(-1,-1);

    ll c=(y-x)/g;

    p.F=zarb(p.F,c);
    p.S=zarb(p.S,c);

    ll w=(zarb(p.S,n)-x)%lc;
    if(w<0) w+=lc;
    ll X=x+w,Y=y+w;
    ANS(((X/n)&1)*n,((Y/m)&1)*m);
}