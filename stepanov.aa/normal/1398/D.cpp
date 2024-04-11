#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long results[201][201][201];


long long solve(vector<int>& r, vector<int>& g, vector<int>& b, int R, int G, int B) {
	int res = 0;
	if (R > 0 && G > 0) {
		if (results[R - 1][G - 1][B] == -1) {
			solve(r, g, b, R - 1, G - 1, B);
		}
		if (res < results[R - 1][G - 1][B] + r[R] * g[G]) {
			res = results[R - 1][G - 1][B] + r[R] * g[G];
		}
	}
	if (G > 0 && B > 0) {
		if (results[R][G - 1][B - 1] == -1) {
			solve(r, g, b, R, G - 1, B - 1);
		}
		if (res < results[R][G - 1][B - 1] + g[G] * b[B]) {
			res = results[R][G - 1][B - 1] + g[G] * b[B];
		}
	}
	if (R > 0 && B > 0) {
		if (results[R - 1][G][B - 1] == -1) {
			solve(r, g, b, R - 1, G, B - 1);
		}
		if (res < results[R - 1][G][B - 1] + r[R] * b[B]) {
			res = results[R - 1][G][B - 1] + r[R] * b[B];
		}
	}
		
	results[R][G][B] = res;
	return res;
}


int main() {
	int R, G, B;
	cin >> R >> G >> B;
	vector<int> r(R);
	vector<int> g(G);
	vector<int> b(B);
	for (int i = 0; i < R; ++i) {
		cin >> r[i];
	}
	for (int i = 0; i < G; ++i) {
		cin >> g[i];
	}
	for (int i = 0; i < B; ++i) {
		cin >> b[i];
	}
	r.push_back(-1);
	g.push_back(-1);
	b.push_back(-1);
	sort(r.begin(), r.end());
	sort(g.begin(), g.end());
	sort(b.begin(), b.end());
	for (int x = 0; x < 201; ++x) {
		for (int y = 0; y < 201; ++y) {
			for (int z = 0; z < 201; ++z) {
				results[x][y][z] = -1;
			}
		}
	}
	cout << solve(r, g, b, R, G, B) << endl;
}