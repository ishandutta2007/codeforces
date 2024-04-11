#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, m, a[N], t;
vector<int> ans[N];
vector<pair<int, int>> bin[N];
int pre[N], tot;

int main() {
	n = get(), m = get();
	for(int i = 1; i <= m; i++) a[i] = get();
	for(int i = 1; i <= m; i++) {
		while(a[i] >= n) {
			++t;
			for(int j = 1; j <= m; j++) ans[t].emplace_back(i);
			a[i] -= n;
		}
	}
	int now = n, top = 0;
	for(int i = 1; i <= m; i++) {
		while(a[i]) {
			if(now == n) ++top, now = 0;
			int tmp = min(n - now, a[i]);
			now += tmp, a[i] -= tmp, bin[top].emplace_back(now, i);
		}
		if(i == m) now = n;
		pre[++tot] = now;
	}
	sort(pre + 1, pre + 1 + tot);
	for(int i = m; i >= 1; i--) pre[i] = pre[i] - pre[i - 1];
	for(int i = 1; i <= top; i++) {
		++t;
		int now = 0, sum = 0;
		for(auto j : bin[i])
			while(sum < j.first) 
				++now, sum += pre[now], ans[t].emplace_back(j.second);
		while(now < m) ++now, ans[t].emplace_back(1);
	}
	
	printf("%d\n", t);
	for(int i = 1; i <= m; i++) printf("%d ", pre[i]); printf("\n");
	for(int i = 1; i <= t; i++, printf("\n"))
		for(auto v : ans[i])
			printf("%d ", v);
	return 0;
}