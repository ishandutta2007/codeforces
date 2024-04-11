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

const int MOD = 1e9 + 7;
double EPS = 1e-10;

char s[10];

int main() {
	int N; cin >> N;
	stack<int> st;
	int y = 1, ans = 0;
	rep(t, N * 2) {
		scanf("%s", &s);
		if (s[0] == 'a') {
			int x; scanf("%d", &x);
			st.push(x);
		}
		if (s[0] == 'r') {
			if (st.empty()) st.push(y);
			if (st.top() == y) st.pop();
			else {
				ans++;
				for (; !st.empty(); st.pop());
			}
			y++;
		}
	}
	cout << ans << endl;
}