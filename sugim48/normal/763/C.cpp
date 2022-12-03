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
#include <vector>
#include <random>
#include <unordered_set>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

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
int INF = INT_MAX / 10;
double EPS = 1e-10;

int M;
bool unko[10000000];
unordered_set<int> st;

void init(vector<int> a) {
	if (M <= 10000000)
		for (int x: a)
			unko[x] = true;
	else
		for (int x: a)
			st.insert(x);
}

bool check(int x) {
	if (M <= 10000000) return unko[x];
	else return st.count(x);
}

int main() {
	random_device rd;
	mt19937 mt(rd());
	int N; cin >> M >> N;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	if (N == 1) {
		cout << a[0] << ' ' << 0 << endl;
		return 0;
	}
	if (M - N == 0) {
		cout << 0 << ' ' << 1 << endl;
		return 0;
	}
	if (M - N == 1) {
		vector<bool> b(M);
		for (int x: a) b[x] = true;
		rep(x, M) if (!b[x]) {
			cout << (x + 1) % M << ' ' << 1 << endl;
			return 0;
		}
	}
	vector<int> ds;
	if (N < M - N)
		for (int i = 1; i < N; i++)
			ds.pb((a[i] - a[0] + M) % M);
	else {
		vector<bool> b(M);
		for (int x: a) b[x] = true;
		vector<int> A;
		rep(x, M) if (!b[x]) A.pb(x);
		for (int i = 1; i < A.size(); i++)
			ds.pb((A[i] - A[0] + M) % M);
	}
	shuffle(ds.begin(), ds.end(), mt);
	shuffle(a.begin(), a.end(), mt);
	init(a);
	for (int d: ds) {
		int cnt = 0;
		for (int x: a) if (!check((x + d) % M)) {
			cnt++;
			if (cnt == 2) break;
		}
		if (cnt == 2) continue;
		for (int x: a) if (!check((x + d) % M)) {
			cout << x << ' ' << (M - d) % M << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}