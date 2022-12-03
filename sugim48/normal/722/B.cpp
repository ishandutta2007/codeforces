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

bool vowel(char c) {
	return c=='a' || c=='i' || c=='u' || c=='e' || c=='o' || c=='y';
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) cin >> a[i];
	cin.ignore();
	rep(i, N) {
		string s;
		getline(cin, s);
		int cnt = 0;
		for (char c: s) if (vowel(c)) cnt++;
		if (cnt != a[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}