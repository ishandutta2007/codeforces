#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, vis[N];
char s[N];

int solve() {
	n = get();
	scanf("%s", s + 1);
	int cntM = 0, cntT = 0;
	for(int i = 1; i <= n; i++) cntM += s[i] == 'M', cntT += s[i] == 'T', vis[i] = s[i] == 'M';
	if(cntM * 2 != cntT) return 0;
	int l = 1;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'M') {
			while(l < i && vis[l]) ++l;
			if(l == i) return 0;
			vis[l] = 1;
		}
	} 
	int r = n;
	for(int i = n; i >= 1; i--) {
		if(s[i] == 'M') {
			while(r > i && vis[r]) --r;
			if(r == i) return 0;
			vis[r] = 1;
		}
	}
	return 1;
}

int main() {
	int T = get();
	while(T--) printf(solve()? "YES\n" : "NO\n"); 
	return 0;
}