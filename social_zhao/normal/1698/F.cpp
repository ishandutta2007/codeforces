#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 505;
int n, a[N], b[N], cnt[N][N];
vector<pair<int, int>> ansA, ansB;
int preA[N], preB[N];

void operateA(int l, int r) { reverse(a + l, a + 1 + r), ansA.emplace_back(l, r); }
void operateB(int l, int r) { reverse(b + l, b + 1 + r), ansB.emplace_back(l, r); }

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= n; i++) b[i] = get();
	memset(cnt, 0, sizeof(cnt));
	if(a[1] != b[1] || a[n] != b[n]) return printf("NO\n"), void();
	
	for(int i = 1; i < n; i++) ++cnt[min(a[i], a[i + 1])][max(a[i], a[i + 1])], --cnt[min(b[i], b[i + 1])][max(b[i], b[i + 1])];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(cnt[i][j]) return printf("NO\n"), void();
	
	ansA.clear(), ansB.clear();
	for(int i = 1; i < n; i++) {
		if(a[i + 1] == b[i + 1]) continue;
		int flag = 0;
		for(int j = i + 2; j <= n && !flag; j++) if(a[j] == a[i] && a[j - 1] == b[i + 1]) flag = j; 
		if(flag) { operateA(i, flag); continue; }
		for(int j = i + 2; j <= n && !flag; j++) if(b[j] == b[i] && b[j - 1] == a[i + 1]) flag = j;
		if(flag) { operateB(i, flag); continue; }
		memset(preA, 0, sizeof(preA)), memset(preB, 0, sizeof(preB));
		for(int j = i + 2; j <= n; j++) {
			if(a[j] == a[i]) preA[a[j - 1]] = j;
			if(b[j] == b[i]) preB[b[j - 1]] = j;
		}
		for(int j = 1; j <= n; j++) if(preA[j] && preB[j]) { operateA(i, preA[j]), operateB(i, preB[j]); flag = 1; break; }
		assert(flag);
	}
	
	reverse(ansB.begin(), ansB.end());
	printf("YES\n");
	printf("%d\n", ansA.size() + ansB.size());
	for(auto v : ansA) printf("%d %d\n", v.first, v.second);
	for(auto v : ansB) printf("%d %d\n", v.first, v.second);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}