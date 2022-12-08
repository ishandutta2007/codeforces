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
string s[N];
map<int, int> vis1, vis2;

int GetHash(string s, int l, int r) {
	int res = 0;
	for(int i = l; i <= r; i++) res = res * 256 + s[i];
	return res;
}

int GetRev(string s, int l, int r) {
	int res = 0;
	for(int i = r; i >= l; i--) res = res * 256 + s[i];
	return res;
}

void solve() {
	n = get(), vis1.clear(), vis2.clear();
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) {
		if(s[i].size() == 1) return printf("YES\n"), void();
		if(s[i].size() == 2 && s[i][0] == s[i][1]) return printf("YES\n"), void();
		if(s[i].size() == 3 && s[i][0] == s[i][2]) return printf("YES\n"), void();
	}
	for(int i = 1; i <= n; i++) {
		if(vis1[GetHash(s[i], 0, s[i].size() - 1)]) return printf("YES\n"), void();
		if(s[i].size() == 2 && vis2[GetHash(s[i], 0, s[i].size() - 1)]) return printf("YES\n"), void();
		if(s[i].size() == 3 && vis1[GetHash(s[i], 1, 2)]) return printf("YES\n"), void();
		vis1[GetRev(s[i], 0, s[i].size() - 1)] = 1;
		if(s[i].size() == 3) vis2[GetRev(s[i], 0, 1)] = 1;
	}
	printf("NO\n");	
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
2
ABC
BA
*/