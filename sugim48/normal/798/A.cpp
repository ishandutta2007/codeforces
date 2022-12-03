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
ll INF = LLONG_MAX / 2;

bool palindrome(string s) {
	int N = s.length();
	rep(i, N) if (s[i] != s[N - 1 - i]) return false;
	return true;
}

int main() {
	string s; cin >> s;
	int N = s.length();
	rep(i, N) for (char c = 'a'; c <= 'z'; c++) {
			if (s[i] == c) continue;
			string _s = s;
			_s[i] = c;
			if (palindrome(_s)) {
				cout << "YES" << endl;
				return 0;
			}
		}
	cout << "NO" << endl;
}