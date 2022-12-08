#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, p[N], len, lent, top, vis[N], Ep[N], pre[N], rev[N], now[N];
vector<int> ans[N];
pii bin[N], tmp[N];

void clear() {
	for(int i = 1; i <= top; i++) ans[i].clear(); top = 0;
}

void comp() {
	for(int i = 1; i <= len; i++) 
		if(!vis[bin[i].first]) tmp[++lent] = bin[i];
		else vis[bin[i].first] = 0;
	for(int i = 1; i <= len; i++) swap(bin[i], tmp[i]), tmp[i] = make_pair(0, 0); swap(len, lent), lent = 0;
	
	//  LIS 
	int lis = 0;
	for(int i = 1; i <= len; i++) now[i] = n + 1;
	for(int i = 1; i <= len; i++) {
		int pos = lower_bound(now, now + 1 + len, bin[i].first) - now;
		lis = max(lis, pos), pre[bin[i].first] = now[pos - 1];
		now[pos] = bin[i].first;
	}
	
	if(lis > Ep[len]) {
		++top;
		int orz = now[lis];
		while(orz) 
			vis[orz] = 1, ans[top].push_back(rev[orz]), orz = pre[orz];
	}
	else {
		for(int i = 1; i <= len; i++) now[i] = n + 1;
		lis = 0;
		for(int i = 1; i <= len; i++) {
			int pos = lower_bound(now, now + 1 + len, bin[i].first) - now;
			lis = max(lis, pos);
			ans[top + pos].emplace_back(bin[i].second), now[pos] = bin[i].first;
		}
		top += lis;
		len = 0;
	}
}

void solve() {
	n = get();
	
	for(int i = 1, k = 1; i <= n; i++) {
		while(k * (k + 1) / 2 <= i) ++k;
		Ep[i] = k - 1;
	}
	
	for(int i = 1; i <= n; i++) p[i] = get(), bin[i] = make_pair(p[i], i), rev[p[i]] = i;
	len = n;
	while(len) comp();
	
	printf("%d\n", top);
	for(int i = 1; i <= top; i++) {
		printf("%d ", ans[i].size());
		sort(ans[i].begin(), ans[i].end());
		for(auto v : ans[i]) printf("%d ", p[v]); printf("\n");
	}
}

int main() {
	int T = get();
	while(T--) solve(), clear();
	return 0;
}