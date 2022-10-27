#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
int T, n;
char s[N+2];

int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%s", s+1); n = strlen(s+1);

		vector<int> pre(n+1);
		map<int,int> up, down;

		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1] + (s[i]=='0'?1:-1);
		}

		for(int i=0;i<n;i++){
			if(pre[i] < pre[i+1]) up[pre[i]] ++;
			else down[pre[i]] ++;
		}

		int now=0;
		for(int i=1;i<=n;i++){
			if(up[now] && (down[now+1] > 0 || down[now] == 0)) {
				up[now] --; now ++; 
				printf("0");
			} else {
				down[now] --; now --; 
				printf("1");
			}
		}
		printf("\n");

	}
}