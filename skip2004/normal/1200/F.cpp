#include<bits/stdc++.h>
const int maxn = 1010;
const int mod = 2520;
using std::cin;
using std::cout;

inline void reduce(int & x) {
	x += x >> 31 & mod;
}

inline int add(int x, int y) {
	return x += y - mod, x + (x >> 31 & mod);
}

int idx[maxn][mod];

int len[maxn][mod];
int in[maxn][mod];

int to[maxn][10], size[maxn];

int k[maxn];

int n, tot;


int bak[maxn * mod];
std::bitset<maxn> set;
inline int ask(int x, int y) {
	y = add(y, k[x]);
	if(~len[x][y]) return len[x][y];
	if(in[x][y]) {
		set.reset();
		for(int i = in[x][y];i <= tot;++i) set.set(bak[i]);
		return len[x][y] = set.count();
	}
	in[x][y] = ++ tot;
	bak[tot] = x;
	return len[x][y] = ask(to[x][y % size[x]], y);
}

int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n;
	for(int i = 0;i < n;++i) {
		cin >> k[i];
		reduce(k[i] %= mod);
	}
	for(int i = 0;i < n;++i) {
		cin >> size[i];
		for(int j = 0;j < size[i];++j) {
			cin >> to[i][j];
			-- to[i][j];
		}
	}
	memset(len, -1, sizeof len);
	int q; cin >> q;
	for(int i = 0;i < q;++i) {
		int x, y;
		cin >> x >> y;
		-- x;
		reduce(y %= mod);
		cout << ask(x, y) << '\n';
	}
}