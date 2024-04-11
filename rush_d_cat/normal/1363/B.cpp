#include <bits/stdc++.h>
using namespace std;
int t;
char s[1002];
int pre[1002];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(s[i]=='1');
		int ans=1e9;
		for(int i=0;i<=n;i++){
			ans=min(ans, pre[i]+(n-i - (pre[n]-pre[i]) ));
			ans=min(ans, i-pre[i] + pre[n]-pre[i]);
		}
		printf("%d\n", ans);
	}
}