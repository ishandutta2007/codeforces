#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 500200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int t, n, p[maxn], ip[maxn];;
int fa[maxn];
int ans[maxn];

int max[maxn];
inline void upt(int cur, int pos, int v, int l = 1, int r = n) {
	if(l == r) {
		max[cur] = v;
		return ;
	}
	int mid = l + r >> 1;
	pos <= mid ? upt(cur << 1, pos, v, l, mid) : upt(cur << 1 | 1, pos, v, mid + 1, r);
	max[cur] = std::max(max[cur << 1], max[cur << 1 | 1]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> t;
	for(;t--;) {
		cin >> n;
		std::set<int> set = {0};
		rep(i, 1, n) {
			cin >> p[i];
			ip[p[i]] = i;
			ans[i] = 1;
			upt(1, i, 1);
			set.emplace(i);
		}
		int good = 1;
		rep(i, 1, n) {
			if(ans[ip[i]] == max[1]) {
				upt(1, ip[i], 0);
				set.erase(ip[i]);
				auto iter = set.lower_bound(ip[i]);
				if(iter != set.end()) {
					upt(1, *iter, ans[*iter] = *iter - *std::prev(iter));
				}
			} else {
				good = 0;
				break;
			}
		}
		cout << (good ? "Yes" : "No") << '\n';
	}
}