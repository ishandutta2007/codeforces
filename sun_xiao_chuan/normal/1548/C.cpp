#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
#define ni 333333336
int i,j,k,n,m,t,sb[100500];
ll jc[3005000],inv[3005000],f1[3005000],res[3005000],pre,inv3,tmp;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;if(a>=M){a-=M;}return a;}

int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=3000100;i++){jc[i]=jc[i-1]*i%M;}
	inv[3000100]=ksm(jc[3000100],M-2);
	for(i=3000099;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	scanf("%d%d",&n,&t);n*=3;
	for(i=0;i<=n+1;i++){
		f1[i]=c(n+3,i+1);//c(0,i) to c(n,i)
		if(i){
			f1[i]=su(f1[i],M-f1[i-1]);
		}
		//printf("a%d %d %d\n",i,f1[i],c(n+3,i+1));
		// 3 0 1 -1 1 -1 ...
	}
	res[0]=n/3+1;
	for(i=1;i<=n;i++){
		tmp=su(f1[i],M-pre);
		tmp=tmp*ni%M;
		res[i]=tmp;
		
		//printf("%d %d %d %d\n",i,res[i],res[i]*3%M,pre);
		
		pre=M-pre;
		pre=su(pre,res[i-1]);
		
	}
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",res[n]%M);
	}
}