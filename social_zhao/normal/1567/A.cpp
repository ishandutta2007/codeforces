#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
char s[N];
int n;

void solve() {
	n = get(), scanf("%s", s + 1);
	int flag = 0;
	for(int i = 1; i <= n; i++) flag |= s[i] == 'D';
	if(flag == 1) {
		for(int i = 1; i <= n; i++) {
			if(s[i] == 'L' || s[i] == 'R') printf("%c", s[i]);
			else printf("U");
		}
		printf("\n");
	}
	else {	
		for(int i = 1; i <= n; i++) {
			if(s[i] == 'L' || s[i] == 'R') printf("%c", s[i]);
			else printf("D");
		}
		printf("\n");
	}
}

int main() {
	int T = get();
	while(T--) solve(); 
	return 0;
}