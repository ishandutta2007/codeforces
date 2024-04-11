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
#include <list>
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
struct edge { ll B, T, F, P; };
 
unsigned MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int UNKO = INT_MAX;
 
int main() {
	vector<int> x(26);
	for (int k = 0; k < 26; k++)
		cin >> x[k];
	string s; cin >> s;
	int n = s.length();
	ll sum = 0, ans = 0;
	vector<map<ll, int> > m(26);
	for (int i = 0; i < n; i++) {
		int k = s[i] - 'a';
		ans += m[k][sum];
		sum += x[k];
		m[k][sum]++;
	}
	cout << ans << endl;
}