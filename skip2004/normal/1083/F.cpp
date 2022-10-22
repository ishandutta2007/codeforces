#include<bits/stdc++.h>
using std::cin;
using std::cout;

const int maxn = 200200;
typedef long long ll;

int n, k, q;
int a[maxn], b[maxn];
struct block {
	short cnt[1 << 14];
	std::vector<int> vec;
	inline void init(int size) {
		vec.resize(size);
		memset(cnt, 0, sizeof cnt);
		cnt[0] = size;
	}
	inline void mdf(int pos, int v) {
		for(int i = pos;i < vec.size();++i) {
			-- cnt[vec[i]];
			vec[i] ^= v;
			++ cnt[vec[i]];
		}
	}
};
struct array {
	static const int B = 512;
	int size, Bc;
	std::vector<block> blocks;
	std::vector<int> vec;
	inline void init() {
		blocks.resize(Bc = size / B);
		for(block &x : blocks) {
			x.init(B);
		}
		vec.resize(size - Bc * B);
	}
	inline int calc() {
		int pre = 0, cnt = 0;
		for(block &x : blocks) {
			cnt += B - x.cnt[pre];
			pre ^= x.vec.back();
		}
		for(int i : vec) if(pre ^= i) 
			++ cnt;
		return pre ? 1e9 : cnt;
	}
	inline void mdf(int pos, int v) {
		if(pos < Bc * B) {
			blocks[pos / B].mdf(pos % B, v);
		} else {
			vec[pos - Bc * B] ^= v;
		}
	}
} vec[maxn];
ll ans;
inline void upt(int pos, int v) {
	ans -= vec[pos % k].calc();
	vec[pos % k].mdf(pos / k, v);
	ans += vec[pos % k].calc();
}
inline int get(int * a, int n) {
	return n ? a[n] ^ a[n - 1] : *a;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k >> q;
	for(int i = 0;i < n;++i) {
		cin >> a[i];
	}
	for(int i = 0;i < n;++i) {
		cin >> b[i];
	}
	for(int i = 0;i <= n;++i) {
		vec[i % k].size = i / k + 1;
	}
	for(int i = 0;i < k;++i) {
		vec[i].init();
	}
	for(int i = n;i >= 0;--i) {
		upt(i, get(a, i) ^ get(b, i));
	}
	cout << (ans <= n ? int(ans) : -1) << '\n';
	for(int i = 0;i < q;++i) {
		char ch; int p, v;
		cin >> ch >> p >> v;
		-- p;
		int & x = p[ch == 'a' ? a : b];
		v ^= x, x ^= v;
		upt(p, v);
		upt(p + 1, v);
		cout << (ans <= n ? int(ans) : -1) << '\n';
	}
}