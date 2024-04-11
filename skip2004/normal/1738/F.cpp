#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 10005;
int t;
int anc[N];
int d[N], rank[N], size[N];
std::vector<int> subset[N];
inline int cmp(int a, int b) {
	return d[a] < d[b];
}
inline int find(int x) {
	return anc[x] == x ? x : anc[x] = find(anc[x]);
}
inline int qry(int p) {
	std::cout << "? " << p << std::endl;
	int r; std::cin >> r;
	return r;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;++i) {
		int n;
		cin >> n;
		for(int i = 1;i <= n;++i) cin >> d[i], rank[i] = i, anc[i] = i, size[i] = 1;
		std::sort(rank + 1, rank + n + 1, cmp);
		for(int i = n;i >= 1;--i) {
			int o = rank[i];
			if(size[find(o)]==1)
			for(int j = 0;j < d[o];++j) {
				int z = qry(o);
				if(size[find(z)] > 1) {
					size[find(z)] += size[find(o)];
					anc[find(o)] = find(z);
					break;
				} else {
					anc[z] = o, size[o] += 1;
				}
			}
		}
		cout << "!";
		for(int i = 1;i <= n;++i) {
			cout << ' ' << find(i);
		}
		cout << std::endl;
	}
}