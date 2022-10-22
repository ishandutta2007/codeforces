#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int N = 2020;
int n;
int p[N], s[N], is[N];
int go[N];
std::vector<std::pair<int, int>> vec;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> p[i];
	rep(i, 1, n) cin >> s[i], is[s[i]] = i;
	rep(i, 1, n) go[i] = is[p[i]];
	ll cost = 0;
	rep(i, 1, n) {
		int x = std::find(go + 1, go + n + 1, i) - go;
		for(int j = x - 1;j >= i;--j) {
			if(go[j] >= x) {
				cost += x - j;
				vec.emplace_back(j, x);
				std::swap(go[j], go[x]);
				x = j;
			}
		}
	}
	cout << cost << '\n';
	cout << vec.size() << '\n';
	for(auto i : vec)
		cout << i.first << ' ' << i.second << '\n';
}