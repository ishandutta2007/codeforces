#include<bits/stdc++.h>
using namespace std;
 
int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}
 
const int N = 2e5 + 5;
int n, mx[3];
char s[3][N];
 
int calc(char *opt) {
	int cnt0 = 0;
	for(int i = 1; i <= 2 * n; i++) cnt0 += opt[i] == '0';
	return cnt0 <= n;
}
 
void merge(char *s1, char *s2, int opt) {
	int l1 = 1, l2 = 1;
	while(l1 <= 2 * n || l2 <= 2 * n) {
		if(l1 > 2 * n) printf("%c", s2[l2]), ++l2;
		else if(l2 > 2 * n) printf("%c", s1[l1]), ++l1;
		else {
			if(s1[l1] == s2[l2]) printf("%c", s1[l1]), ++l1, ++l2;
			else if(s1[l1] - '0' == opt) printf("%c", s2[l2]), ++l2;
			else printf("%c", s1[l1]), ++l1;
		}
	}
	printf("\n");
}
 
void solve() {
	n = get();
	scanf("%s%s%s", s[0] + 1, s[1] + 1, s[2] + 1);
	for(int i = 0; i < 3; i++) mx[i] = calc(s[i]);
	for(int i = 0; i < 3; i++)
		for(int j = i + 1; j < 3; j++)
			if(mx[i] == mx[j]) { merge(s[i], s[j], mx[i]); return; }
}
 
int main() {
	int T = get();
	while(T--) solve();
	return 0;
}
 
/*
1
1
00
11
01
*/