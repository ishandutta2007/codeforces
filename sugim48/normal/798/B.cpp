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
#include <cassert>
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
typedef vector<int> vi;
struct edge { int v; ll w; };
 
const int MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;

int main() {
	int N; cin >> N;
	vector<string> s(N);
	rep(i, N) cin >> s[i];
	int M = s[0].length();
	vector<map<string, int> > mp(N);
	rep(i, N) rep(t, M) {
		if (!mp[i].count(s[i])) mp[i][s[i]] = t;
		rotate(s[i].begin(), s[i].begin() + 1, s[i].end());
	}
	string s0 = s[0];
	int ans = INF;
	rep(t, M) {
		int sum = 0;
		rep(i, N)
			if (mp[i].count(s0)) sum += mp[i][s0];
			else sum = INF;
		ans = min(ans, sum);
		rotate(s0.begin(), s0.begin() + 1, s0.end());
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
}