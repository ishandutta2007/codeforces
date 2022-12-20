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

int tavan(int a,ll b,int md){
    int ans=1;
    while(b>0){
	if(b&1) ans=(1ll*ans*a)%md;
	a=(1ll*a*a)%md;
	b/=2;
    }
    return ans;
}

int main(){
    int q;scanf("%d",&q);
    while(q--){
	ll k,l,r,p;
	scanf("%lld%lld%lld%lld",&k,&l,&r,&p);
	if(p==2){
	    if(k&1) printf("0\n");
	    else printf("1\n");
	    continue;
	}
	int etw=(k&1?tavan(tavan(2,p-2,p),r-l,p):1);
	if(k%p==0){
	    printf("%d\n",etw);
	    continue;
	}
	int A=tavan(k,tavan(2,l,p-1),p)-1;
	if(A==0){
	    printf("%d\n",int(1ll*tavan(2,r-l+1,p)*etw %p));
	    continue;
	}
	int B=tavan(k,tavan(2,r+1,p-1),p)-1;
	printf("%d\n",int(1ll*B*tavan(A,p-2,p) %p *etw %p));
    }
}