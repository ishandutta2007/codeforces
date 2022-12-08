#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n;
char s[N];

int calc(int c) {
	int l = 1, r = n, res = 0;
	while(l < r) {
		if(s[l] == s[r]) ++l, --r;
		else {
			if(s[l] - 'a' == c) ++res, ++l;
			else if(s[r] - 'a' == c) ++res, --r;
			else return 0x3f3f3f3f; 
		}
	}
	return res;
}

void solve() {
	n = get(), scanf("%s", s + 1);
	int ans = 0x3f3f3f3f;
	for(int i = 0; i < 26; i++) 
		ans = min(ans, calc(i));
	if(ans == 0x3f3f3f3f) cout << -1 << endl;
	else cout << ans << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
8
abcaacab
*/