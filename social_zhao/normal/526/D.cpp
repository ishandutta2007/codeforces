#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, k, nxt[N];
char s[N];

int main() {
	n = get(), k = get();
	scanf("%s", s + 1);
	nxt[1] = 0;
	for(int i = 2; i <= n; i++) {
		nxt[i] = nxt[i - 1];
		while(nxt[i] && s[i] != s[nxt[i] + 1]) nxt[i] = nxt[nxt[i]];
		if(s[i] == s[nxt[i] + 1]) ++nxt[i];
	}
	for(int i = 1; i <= n; i++) {
		int cir = i - nxt[i], res = 0, tim = i / cir;
		if(i % cir == 0) printf("%d", tim / k - tim % k >= 0);
		else printf("%d", tim / k - tim % k > 0);
	}
	return 0;
}