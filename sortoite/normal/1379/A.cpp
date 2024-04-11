#include <bits/stdc++.h>

using namespace std;

#define NN 55

char s[NN];
char B[NN];
string p = "abacaba";

int calc(int n) {
	int cnt = 0;
	for(int i=1; i<=n-6; i++) {
		int flag = 1;
		for(int j=0; j<7; j++) if(B[i+j] != p[j]) {
			flag = 0;
		}
		cnt += flag;
	}
	return (cnt == 1);
}

int solve() {
	int n = strlen(s+1);
	for(int i=1; i<=n-6; i++) {
		for(int j=1; j<=n; j++) B[j] = s[j];
		int flag = 1;
		for(int j=0; j<7; j++) {
			if(B[i+j] != p[j] and B[i+j] != '?') {
				flag = 0;
			}
			B[i+j] = p[j];
		}
		for(int j=1; j<=n; j++) if(B[j] == '?') B[j] = 'd';
		if(!calc(n)) flag = 0;
		if(flag) return 1;
	}
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int T; cin >> T;
	
	while(T--) {
		int n; scanf("%d", &n);
		scanf("%s", s+1);
		if(solve()) {
			puts("Yes");
			for(int i=1; i<=n; i++) putchar(B[i]);
			puts("");
		} else puts("No");
	}
	
	return 0;
}