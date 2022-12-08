#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	bool fib[3000];
	fill(fib, fib+1010, false);
	fib[1] = true;
	int cur = 1;
	int prev = 1;
	while (cur <= 1000) {
		int tempo = cur+prev;
		fib[tempo] = true;
		prev = cur;
		cur = tempo;
	}
	for (int i = 1; i <= n; i++) {
		if (fib[i]) cout << "O";
		else cout << "o";
	}
	cout << endl;
	cin >> n;

}