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

ll f(string s) {
	s.push_back('+');
	int n = s.length();
	ll sum = 0, prod = 1, num = 0;
	for (int i = 0; i < n; i++) {
		char c = s[i];
		if ('0' <= c && c <= '9')
			num = num * 10 + (c - '0');
		else {
			prod *= num;
			num = 0;
			if (c == '+') {
				sum += prod;
				prod = 1;
			}
		}
	}
	return sum;
}

int main() {
	string s; cin >> s;
	int n = s.length();
	ll maxi = 0;
	for (int l = 0; l <= n; l++)
		if (l == 0 || s[l - 1] == '*')
			for (int r = l + 1; r <= n; r++)
				if (r == n || s[r] == '*')
					maxi = max(maxi, f(s.substr(0, l) + to_string(f(s.substr(l, r - l))) + s.substr(r)));
	cout << maxi << endl;
}