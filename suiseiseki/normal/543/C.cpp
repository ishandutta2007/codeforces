#include <cstdio>
#include <cstring>
#define Maxn 20
int f[(1<<Maxn)|5];
int a[Maxn+5][Maxn+5];
char s[Maxn+5][Maxn+5];
int num[Maxn+5][26];
int sum[Maxn+5][26];
int maxn[Maxn+5][26];
int change[Maxn+5][26];
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			num[j][s[i][j]-'a']++;
			sum[j][s[i][j]-'a']+=a[i][j];
			maxn[j][s[i][j]-'a']=mx(maxn[j][s[i][j]-'a'],a[i][j]);
			change[j][s[i][j]-'a']|=(1<<(i-1));
		}
	}
	memset(f,0x3f,sizeof f);
	int start=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(num[j][s[i][j]-'a']==1){
				start|=(1<<(i-1));
			}
		}
	}
	f[start]=0;
	for(int i=0;i<(1<<n);i++){
		if((start&i)!=start){
			continue;
		}
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				continue;
			}
			for(int k=1;k<=m;k++){
				f[i|(1<<(j-1))]=mn(f[i|(1<<(j-1))],f[i]+a[j][k]);
				f[i|change[k][s[j][k]-'a']]=mn(f[i|change[k][s[j][k]-'a']],f[i]+sum[k][s[j][k]-'a']-maxn[k][s[j][k]-'a']);
			}
			break;
		}
	}
	printf("%d\n",f[(1<<n)-1]);
	return 0;
}