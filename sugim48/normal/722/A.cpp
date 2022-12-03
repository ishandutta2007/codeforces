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
#include <list>
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
 
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define pb push_back
 
int INF = INT_MAX / 10;
ll MOD = 924844033;
ll _MOD = 1000000009;
double EPS = 1e-10;

char c[100];

int main() {
	int t; cin >> t;
	string s; cin >> s;
	string ans;
	int mi = 5;
	for (int h = 0; h < 24; h++)
		for (int m = 0; m < 60; m++) {
			if (!(t==24 || (1<=h && h<=12))) continue;
			sprintf(c, "%02d:%02d", h, m);
			string t = c;
			int cnt = 0;
			for (int i = 0; i < 5; i++)
				if (s[i] != t[i])
					cnt++;
			if (cnt < mi) mi = cnt, ans = t;
		}
	cout << ans << endl;
}