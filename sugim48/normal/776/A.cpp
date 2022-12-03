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
double EPS = 1e-10;

int main() {
	set<string> st;
	string s1, s2; cin >> s1 >> s2;
	st.insert(s1); st.insert(s2);
	vector<string> v(st.begin(), st.end());
	cout << v[0] << ' ' << v[1] << endl;
	int N; cin >> N;
	while (N--) {
		string s1, s2; cin >> s1 >> s2;
		st.erase(s1); st.insert(s2);
		vector<string> v(st.begin(), st.end());
		cout << v[0] << ' ' << v[1] << endl;
	}
}