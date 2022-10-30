#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int power(int a, int b, int m, int ans=1) {
    for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
    return ans;
}
typedef long long INT;
#define NN 100010
int f[NN];
int g[NN];
int p[NN];
int q[NN];
char s[NN];
int ans[NN];
void pre(){
	f[0]=1;
	g[0]=1;
	p[0]=1;
	for(int i=1;i<NN;i++){
		f[i]=26LL*f[i-1]%mod;
		g[i]=25LL*g[i-1]%mod;
		p[i]=(INT)p[i-1]*i%mod;
	}
	q[NN-1]=power(p[NN-1],mod-2,mod);
	for(int i=NN-2;i>=0;i--) q[i]=(INT)(i+1)*q[i+1]%mod;
}
int C(int n,int k){
	if(k>n) return 0;
	int ans=(INT)q[k]*q[n-k]%mod;
	ans=(INT)ans*p[n]%mod;
	return ans;
}
int m,cur;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	pre();
	int T;
	scanf("%d%s",&T,s+1);
	m=strlen(s+1);
	ans[m]=1;
	cur=m;
	for(int i=1;i<=T;i++){
		int ok;
		scanf("%d",&ok);
		if(ok==1){
			scanf("%s",s+1);
			m=strlen(s+1);
			cur=m;
			ans[m]=1;
		}
		else{
			int n;
			scanf("%d",&n);
			if(m>n){
				puts("0");
				continue;
			}
			if(cur>=n){
				printf("%d\n",ans[n]);
				continue;
			}
			for(int i=cur+1;i<=n;i++){
				ans[i]=((INT)ans[i-1]*26%mod+(INT)g[i-m]*C(i-1,m-1)%mod)%mod;
			}
			cur=n;
			printf("%d\n",ans[n]);
		}
	}
    return 0;
}