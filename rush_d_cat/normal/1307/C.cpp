#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100000 + 10;
char s[N];
int suf[N][27],n;
LL sum[27][27];
int main() {
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=n;i>=1;i--){
		for(int j=0;j<26;j++){
			suf[i][j]=suf[i+1][j];
		}
		suf[i][s[i]-'a']++;
	}
	LL ans=0;
	for(int i=0;i<26;i++)ans=max(ans,1LL*suf[1][i]);
	for(int i=1;i<=n;i++){
		int x=s[i]-'a';
		for(int j=0;j<26;j++){
			sum[x][j]+=suf[i+1][j];
		}
	}
	for(int i=0;i<26;i++)for(int j=0;j<26;j++)ans=max(ans,sum[i][j]);
	cout<<ans<<endl;
}