#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
char a[100100];
int dp[100100];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin>>a+1;
	int n=strlen(a+1);
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1];
		if(a[i]==a[i-1]) dp[i]++;
	}
	for(int i=2;i<=n;i++) cerr<<dp[i]<<endl;
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		int s=dp[r]-dp[l];
		cout<<s<<endl;
	}
	return 0;
}