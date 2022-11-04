#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5 + 3;

int t, n, nxt[128], f[N];
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for(int i = 0; i < 128; i++)
			nxt[i] = n + 1;
		f[n + 1] = 0;
		f[n + 2] = -2;
		for(int i = n; i > 0; i--){
			f[i] = max(f[nxt[s[i]] + 1] + 2, f[i + 1]);
			nxt[s[i]] = i;
		}
		printf("%d\n", n - f[1]);
	}
	return 0;
}