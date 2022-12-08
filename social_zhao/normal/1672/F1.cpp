#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, a[N], cnt[N];
vector<int> bin[N];

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) cnt[i] = 0, bin[i].clear();
	for(int i = 1; i <= n; i++) {
		a[i] = get(), ++cnt[a[i]];
		bin[cnt[a[i]]].emplace_back(i);
	}
	for(int i = 1; i <= n; i++) {
		if(!bin[i].size()) continue;
		sort(bin[i].begin(), bin[i].end(), [](int x, int y) { return a[x] < a[y]; });
		int lst = 0;
		for(int j = bin[i].size() - 1; j >= 0; j--) swap(a[bin[i][j]], lst);
		swap(a[bin[i][bin[i].size() - 1]], lst);
	}
	for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
7
7 2 5 4 7 4 2

2 4 7 7 2 5 4


*/