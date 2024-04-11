#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long INT;
#define NN 100010
int h[NN];
int a[NN];
int n,m,k,p;
int re[NN];
int f[NN];
bool check(INT x){
	for(int i=0;i<m+1;i++) f[i]=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x) return 0;
		INT d=(INT)a[i]*m+h[i]-x;
		if(d<=0) continue;
		if((INT)p*k*m<d) return 0;
		INT r=d%p;
		if(!r) r=p;
		for(;r<=d;r+=p){
			if(r<=h[i]) f[0]++;
			else{
				int t=(r-h[i]+a[i]-1)/a[i];
				if(t>=m) return 0;
				f[t]++;
			}
		}
	}
	INT ans=0;
	for(int i=0;i<m;i++){
		ans=max(0LL,ans+f[i]-k);
	}
	if(!ans) return 1;
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=1;i<=n;i++) scanf("%d%d",&h[i],&a[i]);
	INT st=0,ed=INF;
	while(st+1<ed){
		INT mid=(st+ed)>>1;
		if(check(mid)) ed=mid;
		else st=mid;
	}
	printf("%I64d\n",ed);
    return 0;
}