#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
char s[N];

int main() {
	scanf("%d", &t);
	while(t --) {
		scanf("%s", s+1);
		int n = strlen(s+1);
		if(n%2==1) {
			printf("NO\n");
		}else{
			int cnt=0;
			for(int i=1;i<=n;i++) if(s[i] == '(') cnt++;
			if(cnt > n/2) {
				printf("NO\n");
			} else {
				int need = n / 2 - cnt;

				int sum=0;
				bool ok  =true;
				for(int i=1;i<=n;i++) {
					if(s[i] == '(') sum ++;
					else if (s[i] == ')') sum --;
					else if (s[i] == '?') {
						if (need > 0) {
							need --; sum ++; 
						} else {
							sum --;
						}
					}
					if (sum < 0) ok = false;
				}
				
				printf("%s\n", ok ? "YES" : "NO");
			}
		}
	}	
}