#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	vector<vector<int> > C(2001, vector<int>(2001));
	C[0][0] = 1;
	for (int i = 0; i + 1 <= 2000; i++)
		for (int j = 0; j <= 2000; j++) {
			if (j - 1 >= 0)
				C[i + 1][j - 1] = (C[i + 1][j - 1] + C[i][j]) % MOD;
			if (j + 1 <= 2000)
				C[i + 1][j + 1] = (C[i + 1][j + 1] + C[i][j]) % MOD;
		}
	int N, M; cin >> N >> M;
	string s; cin >> s;
	int x = 0, mi = 0;
	for (int j = 0; j < M; j++) {
		if (s[j] == '(') x++;
		if (s[j] == ')') x--;
		mi = min(mi, x);
	}
	int a = -mi, b = x - mi;
	N -= M;
	int ans = 0;
	for (int l = 0; l <= N; l++) {
		int r = N - l;
		for (int x = 0; x + a <= 2000 && x + b <= 2000; x++)
			ans = (ans + (ll)C[l][x + a] * C[r][x + b]) % MOD;
	}
	cout << ans << endl;
}