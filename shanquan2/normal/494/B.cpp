#include<cstdio>
#include<cstring>
#define M 1000000007
using namespace std;

char s[100100],t[100100];
int f[100100],loc[100100],dp[100100],sum[100100],s2[100100];
int main(){
	scanf("%s%s",&s,&t);
	int ls=strlen(s),lt=strlen(t);
	f[0]=-1;
	for(int j=1;j<lt;j++)
		if(t[j]==t[f[j-1]+1])
			f[j]=f[j-1]+1;
		else{
			int i=f[j-1];
			while(i>=0 && t[j]!=t[i+1])i=f[i];
			if(t[j]==t[i+1])f[j]=i+1;else f[j]=-1;
		}
	int cnt=0;
	for(int i=0,j=0;i<ls;){
		if(t[j]==s[i]){
			i++;j++;
		}else
			if(j==0)i++;else j=f[j-1]+1;
		if(j>=lt){
			loc[cnt++]=i;
			j=f[j-1]+1;
		}
	}
//	printf("%d\n",cnt);
	int now=0;dp[0]=0;sum[0]=s2[0]=0;
	for(int i=0;i<ls;i++){
		dp[i+1]=0;
		if(now<cnt && i>=loc[now]-1)now++;
		if(now==0)continue;
		dp[i+1]+=s2[loc[now-1]-lt]+loc[now-1]-lt+1;
		dp[i+1]%=M;
		sum[i+1]=sum[i]+dp[i+1];
		sum[i+1]%=M;
		s2[i+1]=s2[i]+sum[i+1];
		s2[i+1]%=M;
	}
	printf("%d\n",(sum[ls]+M)%M);
	return 0;
}