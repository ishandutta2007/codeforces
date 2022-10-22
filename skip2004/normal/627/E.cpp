#include<bits/stdc++.h>
const int maxn = 3010;
std::vector<int> v[maxn];
long long sum;
int pre[maxn], nxt[maxn], cnt[maxn], ans[maxn];
int r, n, c, k;
int s0;
inline void update(int x,int end) {
	int s = cnt[x], o = x;
	for(;x != end;s -= cnt[x], x = nxt[x]) {
		s0 -= ans[x];
		for(;s < k && o <= c;) s += cnt[o = nxt[o]];
		s0 += ans[x] = (x - pre[x]) * (c - o + 1);
	}
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> r >> c >> n >> k;
	for(int i = 1, x, y;i <= n;++i) 
		std::cin >> x >> y, v[x].push_back(y);
	for(int i = 1;i <= r;++i) {
		memset(cnt, 0, c + 2 << 2);
		memset(pre, 0, c + 2 << 2);
		memset(nxt, 0, c + 2 << 2);
		memset(ans, 0, c + 2 << 2);
		for(int j = i;j <= r;++j) for(int k : v[j]) ++ cnt[k];
		for(int i = 1, p = 0;i <= c + 1;++i) if(cnt[i] || i > c) 
			pre[i] = p, nxt[p] = i, p = i;
		s0 = 0, update(0, c + 1); nxt[c + 1] = c + 1;
		for(int j = r;j >= i;--j) {
			sum += s0;
			for(int x : v[j]) {
				if(!--cnt[x]) nxt[pre[x]] = nxt[x], pre[nxt[x]] = pre[x], s0 -= ans[x];
				int o = x;
				for(int i = 0;i < k;++i) o = pre[o];
				update(o, nxt[nxt[x]]);
			}
		}
	}
	std::cout << sum << '\n';
}