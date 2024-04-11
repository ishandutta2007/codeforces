#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, k, a[N], ans[N], vis[N];
int st[N], top;
set<int> s;

int main() {
	n = get(), k = get();
	if(k == 0) {
		for(int i = n; i >= 1; i--) printf("%d ", i); printf("\n");
		return 0;
	}
	for(int i = 1; i <= k; i++) ans[i] = a[i] = get(), vis[a[i]] = 1;
	for(int i = 1; i <= n; i++) if(!vis[i]) s.insert(i);
	st[++top] = a[1];
	int lst = 0;
	st[0] = n + 1;
	for(int i = 2; i <= k; i++) {
		while(top && a[i] > st[top]) {
			if(st[top] != lst + 1) return printf("-1"), 0;
			lst = st[top], top--;
		}
		st[++top] = a[i];
	}
	for(int i = k + 1; i <= n; i++) {
		while(top && st[top] == lst + 1) lst = st[top], top--;
		set<int>::iterator it = s.lower_bound(st[top]);
		if(it == s.begin()) return printf("-1"), 0;
		--it;
		ans[i] = *it, st[++top] = *it, s.erase(it);
	}
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}