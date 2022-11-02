#include <iostream>
using namespace std;
int n, p[200009], b[200009], par[200009];
int root(int x) {
	if (x == par[x]) return x;
	return par[x] = root(par[x]);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) par[i] = i;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		par[root(i)] = root(--p[i]); p[i] = 0;
	}
	int z = 1;
	for (int i = 0; i < n; i++) cin >> b[i], z ^= b[i];
	int ret = 0;
	for (int i = 0; i < n; i++) p[root(i)] = 1;
	for (int i = 0; i < n; i++) ret += p[i];
	cout << (ret > 1 ? ret : 0) + z << endl;
	return 0;
}