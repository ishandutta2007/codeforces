#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
typedef long long ll;
const int Maxn=10000;
const int Mod=1000000007;
int p,q,n,m,len;
int a[Maxn+5];
int b[Maxn+5];
char s[Maxn+5];
int f[2][Maxn+5][2][2];
int div(int x){
	ll num=0;
	len=0;
	for(int i=1;i<=m;i++){
		num=num*10+a[i];
		if(len>0||num>=x){
			a[++len]=num/x;
		}
		num%=x;
	}
	for(int i=len+1;i<=m;i++){
		a[i]=0;
	}
	m=len;
	return num;
}
int main(){
	read(p),read(q);
	scanf("%s",s+1);
	while(s[++m]!='\0');
	m--;
	for(int i=1;i<=m;i++){
		a[i]=s[i]-'0';
	}
	while(m){
		b[++n]=div(p);
	}
	for(int i=1;i<=n;i++){
		a[i]=b[n-i+1];
	}
	if(n==0){
		puts("0");
		return 0;
	}
	f[0][0][1][0]=1;
	for(int i=1;i<=n;i++){
		int tmp_0=1ll*p*(p+1)/2%Mod,tmp_1=1ll*p*(p-1)/2%Mod,tmp_2=1ll*a[i]*(a[i]+1)/2%Mod,tmp_3=1ll*a[i]*(a[i]-1)/2%Mod,tmp_4=1ll*a[i]*(p+p-a[i]-1)/2%Mod,tmp_5=1ll*a[i]*(p+p-a[i]+1)/2%Mod;
		memset(f[1],0,sizeof f[1]);
		for(int j=0;j<i;j++){
			f[1][j][0][0]=(f[1][j][0][0]+1ll*f[0][j][0][0]*tmp_0+1ll*f[0][j][1][0]*tmp_2)%Mod;
			f[1][j][0][1]=(f[1][j][0][1]+1ll*f[0][j][0][0]*tmp_1+1ll*f[0][j][1][0]*tmp_3)%Mod;
			f[1][j][1][0]=(f[1][j][1][0]+1ll*f[0][j][1][0]*(a[i]+1))%Mod;
			f[1][j][1][1]=(f[1][j][1][1]+1ll*f[0][j][1][0]*a[i])%Mod;
			f[1][j+1][0][0]=(f[1][j+1][0][0]+1ll*f[0][j][0][1]*tmp_1+1ll*f[0][j][1][1]*tmp_4)%Mod;
			f[1][j+1][0][1]=(f[1][j+1][0][1]+1ll*f[0][j][0][1]*tmp_0+1ll*f[0][j][1][1]*tmp_5)%Mod;
			f[1][j+1][1][0]=(f[1][j+1][1][0]+1ll*f[0][j][1][1]*(p-a[i]-1))%Mod;
			f[1][j+1][1][1]=(f[1][j+1][1][1]+1ll*f[0][j][1][1]*(p-a[i]))%Mod;
		}
		swap(f[0],f[1]);
	}
	int ans=0;
	for(int i=q;i<=n;i++){
		ans=(ans+f[0][i][0][0])%Mod;
		ans=(ans+f[0][i][1][0])%Mod;
	}
	printf("%d\n",ans);
	return 0;
}