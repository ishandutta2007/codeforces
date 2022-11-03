#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000007

int dp[2000005],dp2[2000005];
int n,k;
char s[1000005];
int lst[27];

int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int m=strlen(s+1);
	dp[0]=1;
	for(int i=1;i<=m;i++){
		dp[i]=dp[i-1]*2%Mod;
		dp2[i]=dp[i-1];
		if(lst[s[i]-'a']){
			dp[i]=(dp[i]-dp2[lst[s[i]-'a']]+Mod)%Mod;
		}
		lst[s[i]-'a']=i;
		//cerr<<i<<' '<<dp[i]<<endl;
	}
	for(int i=m+1;i<=m+n;i++){
		int minx=Mod,minpos;
		for(int j=0;j<k;j++){
			if(lst[j]<minx){
				minx=lst[j];
				minpos=j;
			}
		}
		dp[i]=dp[i-1]*2%Mod;
		dp2[i]=dp[i-1];
		if(lst[minpos]){
			dp[i]=(dp[i]-dp2[lst[minpos]]+Mod)%Mod;
		}
		lst[minpos]=i;
	}
	printf("%d\n",dp[m+n]);
	return 0;
}