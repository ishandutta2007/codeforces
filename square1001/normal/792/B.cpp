#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, x; bool ok[109];
int main() {
	cin >> N >> K;
	int pos = 0;
	for (int i = 0; i < K; i++) {
		if (i) cout << ' ';
		cin >> x;
		vector<int> w;
		for (int j = pos; j < pos + N; j++) {
			if (!ok[j % N]) w.push_back(j % N);
		}
		int res = x % w.size();
		cout << w[res] + 1;
		ok[w[res]] = true;
		pos = w[(res + 1) % w.size()];
	}
	return 0;
}