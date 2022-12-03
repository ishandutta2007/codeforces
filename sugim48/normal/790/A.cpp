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
#include <fstream>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };

const int MOD = 1000000007;
const int _MOD = 1000000009;
double EPS = 1e-10;
const int INF = INT_MAX / 10;

int main() {
	int N, K; cin >> N >> K;
	vector<string> names;
	for (char C = 'A'; C <= 'Z'; C++)
		for (char c = 'a'; c <= 'z'; c++) {
			string s; s.pb(C); s.pb(c);
			names.pb(s);
		}
	vector<string> a(N);
	rep(i, K - 1) a[i] = names[i];
	for (int i = K - 1; i < N; i++) {
		string s; cin >> s;
		if (s == "YES") a[i] = names[i];
		if (s == "NO") a[i] = a[i - (K - 1)];
	}
	rep(i, N) cout << a[i] << ' ';
	cout << endl;
}