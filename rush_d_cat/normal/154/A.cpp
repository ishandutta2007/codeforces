#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
char s[N]; int k,n,m[30][30],dp[N][30]; 
int main() {
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		char t[3]; scanf("%s",t);
		m[t[0]-'a'][t[1]-'a']=1;
		m[t[1]-'a'][t[0]-'a']=1;
	}
	//printf("ok\n");
	for(int i=0;i<N;i++)for(int j=0;j<30;j++)dp[i][j]=-1000000;
	for(int i=1;i<=n;i++)dp[i][s[i]-'a']=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<26;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j]);
			if(m[s[i]-'a'][j]==0)dp[i][s[i]-'a']=max(dp[i][s[i]-'a'],dp[i-1][j]+1);
		}
	}
	int mx=0;
	for(int i=0;i<26;i++)mx=max(mx,dp[n][i]);
	cout<<n-mx<<endl;
}