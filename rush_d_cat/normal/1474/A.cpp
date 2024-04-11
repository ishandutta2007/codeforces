#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n; char s[N];
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%s",&n,s+1);
		int las=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j>=0;j--){
				int sum=j+(s[i]-'0');
				if(sum==las) continue;
				printf("%d", j);
				las=sum;
				break;
			}
		}
		printf("\n");
	}
}