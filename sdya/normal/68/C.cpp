#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 7;
int n;
int l[maxN][maxN], h[maxN][maxN], a[maxN][maxN];
int f[maxN][maxN];
vector < pair < int, int > > edges;

int res = 1000000, cost = -1;

bool isValid() {
	for (int i = 2; i < n; ++i) {
		int in = 0, out = 0;
		int min_in = 0, max_in = 0;
		int min_out = 0, max_out = 0;
		for (int j = 1; j < i; ++j) {
			if (f[j][i] == -1) {
				min_in += l[j][i];
				max_in += h[j][i];
			} else {
				in += f[j][i];
			}
		}
		for (int j = i + 1; j <= n; ++j) {
			if (f[i][j] == -1) {
				min_out += l[i][j];
				max_out += h[i][j];
			} else {
				out += f[i][j];
			}
		}
		if (in + max_in >= out + min_out && in + min_in <= out + max_out) {
			continue;
		} else {
			return false;
		}
	}
	return true;
}

void rec(int index) {
	int total = 0;
	for (int i = 2; i <= n; ++i) {
		if (f[1][i] == -1) {
			total = -1;
			break;
		} else {
			total += f[1][i];
		}
	}
	if (total > res) {
		return;
	}
	if (index == edges.size()) {
		int total = 0;
		for (int i = 2; i <= n; ++i) {
			total += f[1][i];
		}
		int price = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (f[i][j] > 0) {
					price += a[i][j] + f[i][j] * f[i][j];
				}
			}
		}
		if (total < res || (total == res && price > cost)) {
			res = total;
			cost = price;
		}
		return ;
	}

	int x = edges[index].first;
	int y = edges[index].second;
	for (int c = l[x][y]; c <= h[x][y]; ++c) {
		f[x][y] = c;
		if (isValid()) {
			rec(index + 1);
		}
		f[x][y] = -1;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n * (n - 1) / 2; ++i) {
		int S, F, L, H, A;
		cin >> S >> F >> L >> H >> A;
		l[S][F] = L;
		h[S][F] = H;
		a[S][F] = A;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			edges.push_back(make_pair(i, j));
		}
	}

	memset(f, -1, sizeof(f));
	rec(0);

	if (res == 1000000) {
		cout << -1 << " " << -1 << endl;
	} else {
		cout << res << " " << cost << endl;
	}



	return 0;
}