#include <bits/stdc++.h>
#define x first
#define y second
#define mod 1000000007
using namespace std;
int power(int a, int b, int m, int ans=1) {
    for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
    return ans;
}
typedef long long INT;
typedef pair<int,int> pii;
#define NN 200010
pii p[NN];
int f[NN];
int g[NN];
int dp[NN];
void pre(){
	f[0]=1;
	for(int i=1;i<NN;i++) f[i]=(INT)f[i-1]*i%mod;
	g[NN-1]=power(f[NN-1],mod-2,mod);
	for(int i=NN-2;i>=0;i--) g[i]=(INT)g[i+1]*(i+1)%mod;
}
int C(int n,int k){
	int ans=(INT)g[k]*g[n-k]%mod;
	ans=(INT)ans*f[n]%mod;
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	pre();
	int h,w,n;
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		p[i].x=u;
		p[i].y=v;
	}
	sort(p+1,p+n+1);
	int nn=unique(p+1,p+n+1)-p-1;
	p[0]=pii(1,1);
	for(int i=nn;i>=0;i--){
		int u=p[i].x;
		int v=p[i].y;
		dp[i]=C(h-u+w-v,h-u);
		for(int j=i+1;j<=nn;j++){
			int uu=p[j].x;
			int vv=p[j].y;
			if(vv<v) continue;
			dp[i]=(dp[i]+mod-(INT)dp[j]*C(uu-u+vv-v,uu-u)%mod)%mod;
		}
	}
	printf("%d\n",dp[0]);
    return 0;
}