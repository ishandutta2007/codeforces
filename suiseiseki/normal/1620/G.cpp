#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=23;
const int Maxm=20000;
const int Maxv=26;
const int Inf=0x3f3f3f3f;
const int Mod=998244353;
int n;
int a[1<<Maxn|5];
int num[Maxn+5][Maxv+5];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		static char s[Maxm+5];
		scanf("%s",s+1);
		int m=0;
		while(s[++m]!='\0');
		m--;
		for(int j=1;j<=m;j++){
			num[i][s[j]-'a']++;
		}
	}
	for(int i=1;i<(1<<n);i++){
		static int cnt[Maxv+5];
		for(int j=0;j<Maxv;j++){
			cnt[j]=Inf;
		}
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				for(int k=0;k<26;k++){
					cnt[k]=std::min(cnt[k],num[j][k]);
				}
			}
		}
		if(__builtin_popcount(i)&1){
			a[i]=1;
		}
		else{
			a[i]=Mod-1;
		}
		for(int j=0;j<26;j++){
			a[i]=1ll*a[i]*(cnt[j]+1)%Mod;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<n);j++){
			if((j>>i)&1){
				a[j]=(a[j]+a[j^(1<<i)])%Mod;
			}
		}
	}
	ll ans=0;
	for(int i=0;i<(1<<n);i++){
		int sum=0;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				sum+=(j+1);
			}
		}
		ans^=1ll*(__builtin_popcount(i)*sum)*a[i];
	}
	printf("%lld\n",ans);
	return 0;
}