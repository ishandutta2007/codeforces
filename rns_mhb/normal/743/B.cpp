#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int calc(int n, LL k) {
	for (int i = n - 1; i >= 0; i --) {
		k %= 1ll << i;
		if (!k) return i + 1;
	}
}

int n;
LL k;

int main() {
//	freopen("b.in", "r", stdin);
    cin >> n >> k;
    cout << calc(n, k) << endl;
	return 0;
}