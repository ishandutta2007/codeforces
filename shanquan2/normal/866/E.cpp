#include<bits/stdc++.h>
using namespace std;

int cnt[1<<13],a[25],b[25],n,m,c[1<<14];
char s[25];
long long f[1<<14],ans;
int main(){
	for(int i=1;i<1<<13;i++)cnt[i]=cnt[i>>1]+(i&1);
	scanf("%s",s);n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')a[i]=s[i]-'0';else a[i]=s[i]-'a'+10;
		m+=a[i];
	}
	if(m%15){
		printf("NO\n");
		return 0;
	}
	m/=15;ans=1ll<<60;
	for(int i=0;i<1<<n-1;i++)if(cnt[i]==m){
		for(int j=0;j<n;j++)b[j]=a[j];
		for(int j=0;j<n-1;j++)if(i>>j&1){
			b[n-1-j]-=16;
			b[n-2-j]++;
		}
		memset(c,0,sizeof(c));
		for(int i=0;i<n;i++)c[1<<i]=b[i];
		for(int i=0;i<n;i++)for(int j=0;j<1<<n;j++)if(j>>i&1)c[j]+=c[j^1<<i];
		memset(f,62,sizeof(f));f[1]=0;
		for(int i=1;i<1<<n;i+=2)if(c[i]>=0&&c[i]<16)
			for(int k=0;k<n;k++)if(!(i>>k&1)){
				f[i|1<<k]=min(f[i|1<<k],f[i]|1ll*c[i]<<4*(n-1-k));
			}
		if(f[(1<<n)-1]<ans)ans=f[(1<<n)-1];
	}
	if(ans<1ll<<4*n){
		for(int i=n-1;i>=0;i--){
			int x=ans&15;ans>>=4;
			if(x<10)s[i]='0'+x;else s[i]='a'+x-10;
		}
		printf("%s\n",s);
	}else printf("NO\n");
	return 0;
}