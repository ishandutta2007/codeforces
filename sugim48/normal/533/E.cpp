#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <map>
#include <queue>
#include <random>
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
	int n; cin >> n;
	string S, T; cin >> S >> T;
	int l = 0, r = n;
	for (; l < n && S[l] == T[l]; l++);
	for (; r > 0 && S[r - 1] == T[r - 1]; r--);
	S = S.substr(l, r - l);
	T = T.substr(l, r - l);
	n = S.length();
	int x = 1, y = 1;
	for (int i = 0; i + 1 < n; i++)
		if (S[i] != T[i + 1])
			x = 0;
	for (int i = 0; i + 1 < n; i++)
		if (S[i + 1] != T[i])
			y = 0;
	cout << x + y << endl;
}