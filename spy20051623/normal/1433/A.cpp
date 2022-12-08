#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		char s[10];
		scanf("%s",s);
		int n=strlen(s);
		int c[]={0,1,3,6,10};
		int ans=10*(s[0]-'1')+c[n];
		printf("%d\n",ans);
	}
	return 0;
}