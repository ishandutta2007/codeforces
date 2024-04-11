#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <unordered_set>
#include <vector>
#include <random>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int M, N; cin >> M >> N;
	vector<int> x0(M), y0(M);
	for (int j = 0; j < M; j++)
		cin >> x0[j] >> y0[j];
	vector<int> x(N), y(N);
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	vector<vector<vector<int> > > unko(M, vector<vector<int> >(N));
	for (int j = 0; j < M; j++)
		for (int i = 0; i < N; i++)
			for (int _i = 0; _i < N; _i++) {
				ll dx1 = x0[j] - x[_i], dy1 = y0[j] - y[_i];
				ll dx2 = x[i] - x[_i], dy2 = y[i] - y[_i];
				if (unko[j][i].size() < M && dx1 * dx2 + dy1 * dy2 < 0 && dx1 * dy2 - dx2 * dy1 == 0)
					unko[j][i].push_back(_i);
			}
	vector<bool> pushed(N);
	vector<int> who(N);
	int ans = 0;
	for (int s = 0; s < N; s++) {
		vector<int> p(M);
		for (int j = 0; j < M; j++) p[j] = j;
		do {
			stack<int> st;
			st.push(s);
			pushed[s] = true;
			vector<int> target(M, -1);
			bool ok = true;
			int rest = M;
			for (int j: p) {
				if (st.empty()) break;
				int i = st.top(); st.pop();
				target[j] = i;
				who[i] = j;
				if (unko[j][i].size() == M) {
					ok = false;
					break;
				}
				for (int _i: unko[j][i])
					if (!pushed[_i]) {
						st.push(_i);
						pushed[_i] = true;
					}
				rest--;
				if (st.size() > rest) {
					ok = false;
					break;
				}
			}
			while (!st.empty()) {
				pushed[st.top()] = false;
				st.pop();
			}
			for (int i: target)
				if (i != -1)
					pushed[i] = false;
			if (!ok) continue;
			vector<vector<int> > g(M, vector<int>(M));
			for (int j = 0; j < M; j++) {
				int i = target[j];
				if (i == -1) continue;
				for (int _i: unko[j][i])
					g[j][who[_i]] = 1;
			}
			for (int k = 0; k < M; k++)
				for (int i = 0; i < M; i++)
					for (int j = 0; j < M; j++)
						g[i][j] |= g[i][k] & g[k][j];
			for (int j = 0; j < M; j++)
				if (g[j][j])
					ok = false;
			if (ok) {
				ans++;
				break;
			}
		} while (next_permutation(p.begin(), p.end()));
	}
	cout << ans << endl;
}