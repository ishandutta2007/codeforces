#include <cstdio>
#define Maxn 100000
#define Mod 1000000007
char s[Maxn+5];
int n;
int f[Maxn+5];
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=(f[i-1]+f[i-2])%Mod;
	}
	int ans=1;
	for(int i=1,j;i<=n;i=j+1){
		if(s[i]=='m'||s[i]=='w'){
			puts("0");
			return 0;
		}
		j=i;
		while(j<=n&&s[j]==s[i]){
			j++;
		}
		j--;
		if(s[i]=='u'||s[i]=='n'){
			ans=1ll*ans*f[j-i+1]%Mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}