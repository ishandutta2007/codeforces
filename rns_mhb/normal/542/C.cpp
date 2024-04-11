#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define max(a,b) (a>b?a:b)
#define M 301
ll a[M];
int f[M],num[M];

ll gcd(ll x,ll y){
	if(!y) return x;
	return gcd(y,x%y);
}

ll lcm(ll x,ll y){
	return 1ll*x/gcd(x,y)*y;
}

int main(){
	//freopen("c.in","r",stdin);
	//freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&f[i]);
	int mi=0;
    for(int i=1;i<=n;i++) {
        memset(num,-1,sizeof(num));
		int st=i,jugi,m;
		num[st]=0;
        while(1) {
        	if(num[f[st]]>=0) {jugi=num[st]+1-num[f[st]],m=num[f[st]];break;}
            else {num[f[st]]=num[st]+1;st=f[st];}
        }
        mi=max(m,mi);
        a[i]=jugi;
    }
    ll st=1;
    for(int i=1;i<=n;i++) st=lcm(st,a[i]);
    ll ans=st;
    while(ans<mi) ans+=st;
    printf("%I64d\n",ans);
}