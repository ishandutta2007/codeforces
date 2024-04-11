#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n;
char s[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,s+1);
		int c=0;
		for(int i=1;i<n;i++)
			if(s[i]==s[i+1]) c++;
		printf("%d\n", (c+1)/2);
	}
}