#include <bits/stdc++.h>

using namespace std;

const int maxn = (1 << 12) + 10;

int n, m, q;
int k;

int freq[maxn];
int stuff[maxn][104];
int w[15];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	int allones = (1 << 12)-1;
	string cur;
	for (int i = 0; i < m; i++) {
		cin >> cur;
		int num = 0;
		for (int j = 0; j < n; j++) {
			num *= 2;
			num += cur[j]-'0';
		}
		freq[num]++;
	}
	int cans = 0;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = i; j < (1 << n); j++) {
			int cans = 0;
			int cv = (allones ^ (i ^ j));
			for (int ii = 0; ii < n; ii++) {
				if (  cv & (1 << (n-ii-1))) {
					cans += w[ii];
				}
			}
			if (cans <= 100) {
				stuff[i][cans] += freq[j];
				if (i != j) stuff[j][cans] += freq[i];
			}

		}
	}
	for (int i = 0; i < (1 << 12); i++) {
		for (int j = 1; j <= 100; j++) {
			stuff[i][j] += stuff[i][j-1];
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> cur >> k;
		int num = 0;
		for (int j = 0; j < n; j++) {
			num*=2;
			num += cur[j]-'0';
		}
		cout << stuff[num][k]<< '\n';
	}
	cout.flush();
}