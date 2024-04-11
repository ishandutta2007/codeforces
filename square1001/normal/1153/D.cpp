#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int N;
	cin >> N;
	vector<int> op(N), par(N);
	for (int i = 0; i < N; ++i) cin >> op[i];
	for (int i = 1; i < N; ++i) cin >> par[i], --par[i];
	vector<int> sub(N), mx(N, 0);
	vector<bool> leaf(N, true);
	for (int i = N - 1; i >= 0; --i) {
		if (leaf[i]) ++sub[i];
		if (op[i] == 1) mx[i] += sub[i] - inf;
		if (sub[i] == 1) mx[i] = 0;
		if (i >= 1) {
			leaf[par[i]] = false;
			sub[par[i]] += sub[i];
			if (op[par[i]] == 1) mx[par[i]] = max(mx[par[i]], inf - (sub[i] - mx[i]));
			else mx[par[i]] += mx[i];
		}
	}
	cout << mx[0] + 1 << endl;
	return 0;
}