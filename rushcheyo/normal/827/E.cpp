#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500005,P=998244353,G=3;
int n,l,a[4*N],b[4*N],ans[N],tot;
bool dp[N];
char s[N];
int fpw(int a,int x){
	int ans=1;
	for(;x;a=1ll*a*a%P,x>>=1)if(x&1)ans=1ll*ans*a%P;
	return ans;
}
void dft(int *a,int inv){
	for(int i=0,j=0;i<l;i++){
		if(i>j)swap(a[i],a[j]);
		for(int k=l>>1;(j^=k)<k;k>>=1);
	}
	for(int i=2;i<=l;i<<=1){
		int m=i>>1,wn=fpw(G,P-1+inv*(P-1)/i);
		for(int *p=a;p<a+l;p+=i)
			for(int k=0,w=1;k<m;k++){
				int t=1ll*p[m+k]*w%P;
				p[m+k]=(p[k]+P-t)%P;
				p[k]=(p[k]+t)%P;
				w=1ll*w*wn%P;
			}
	}
	if(inv==-1)for(int i=0,t=fpw(l,P-2);i<l;i++)a[i]=1ll*a[i]*t%P;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s);
		for(l=1;l<2*n;l<<=1);
		for(int i=0;i<l;i++)a[i]=b[i]=0;
		for(int i=0;i<n;i++)
			if(s[i]=='V')a[n-i-1]=1;
			else if(s[i]=='K')b[i]=1;
		dft(a,1),dft(b,1);
		for(int i=0;i<l;i++)a[i]=1ll*a[i]*b[i]%P;
		dft(a,-1);
		for(int i=1;i<=n;i++)dp[i]=false;
		for(int i=0;i<2*n-1;i++)
			if(a[i])dp[abs(i-n+1)]=true;
		for(int i=1;i<n;i++)
			if(!dp[i])
				for(int j=i<<1;j<n;j+=i)
					if(dp[j]){dp[i]=true;break;}
		tot=0;
		for(int i=1;i<=n;i++)
			if(!dp[i])ans[++tot]=i;
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++)printf("%d%c",ans[i]," \n"[i==tot]);
	}
	return 0;
}