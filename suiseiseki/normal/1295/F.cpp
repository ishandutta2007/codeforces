#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=50;
const int Mod=998244353;
int l[Maxn+5],r[Maxn+5];
int d[Maxn<<1|5],d_len;
int n;
int c[Maxn<<1|5][Maxn+5];
int f[Maxn+5];
int inv[Maxn+5];
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	int ans=1;
	for(int i=0;i<n;i++){
		scanf("%d%d",&l[i],&r[i]);
		r[i]++;
		d[++d_len]=l[i];
		d[++d_len]=r[i];
		ans=1ll*ans*(r[i]-l[i])%Mod;
	}
	for(int i=1;i<=n;i++){
		inv[i]=ksm(i,Mod-2);
	}
	sort(d+1,d+1+d_len);
	d_len=unique(d+1,d+1+d_len)-d-1;
	for(int i=0;i<n;i++){
		l[i]=lower_bound(d+1,d+1+d_len,l[i])-d;
		r[i]=lower_bound(d+1,d+1+d_len,r[i])-d;
	}
	for(int i=1;i<d_len;i++){
		c[i][0]=1;
		for(int j=1;j<=n;j++){
			c[i][j]=1ll*c[i][j-1]*(j-1+d[i+1]-d[i])%Mod*inv[j]%Mod;
		}
	}
	f[0]=1;
	for(int i=d_len;i>0;i--){
		for(int j=n-1;j>=0;j--){
			for(int k=j;k<n;k++){
				if(i<l[k]||i>=r[k]){
					break;
				}
				f[k+1]=(f[k+1]+1ll*f[j]*c[i][k-j+1]%Mod)%Mod;
			}
		}
	}
	printf("%d\n",(int)(1ll*f[n]*ksm(ans,Mod-2)%Mod));
	return 0;
}