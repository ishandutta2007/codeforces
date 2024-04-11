#include <bits/stdc++.h>

using namespace std;

#define maxn 5010

int f[maxn];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	bool ans = false;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}
	for (int i = 1; i <= n; i++) {
		if (f[f[f[i]]] == i ) ans = true;
	}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
	cin >> n;

}