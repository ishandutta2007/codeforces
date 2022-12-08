#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	int cur[n];
	for (int i = 0; i < n; i++) {
		cur[i] = -1;
	}
	int p;
	for (int i = 0; i < m; i++) {
		cin >> p;
		p--;
		if (p >= c/2) {
			int best = n-1;
			for (int j = n-1; j >= 0; j--) {
				if (cur[j] >= p) best = j-1;
			}
			cout << best+1 << endl;
			cur[best] = p;
		}
		else {
			int best = 0;
			for (int j = 0; j < n-1; j++) {
				if (cur[j] == -1) continue;
				if (cur[j] <= p) best = j+1;
			}
			cur[best] = p;
			cout << best+1 << endl;
		}
		bool fin = true;
		if (cur[0] == -1) fin = false;
		for (int j = 1; j < n; j++) {
			if (cur[j] == -1) fin = false;
			if (cur[j] < cur[j-1]) fin = false;
		}
		if (fin) break;
	}
	cin >> n;
}