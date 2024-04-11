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

vector<int> solve(vector<int> a, vector<int> b) {
	int N = a.size();
	vector<i_i> ai(N);
	rep(i, N) ai[i] = i_i(a[i], i);
	sort(ai.rbegin(), ai.rend());
	priority_queue<i_i> pq;
	vector<int> p;
	rep(t, N) {
		int i = ai[t].second;
		pq.push(i_i(b[i], i));
		if (t % 2 == 0) {
			p.pb(pq.top().second);
			pq.pop();
		}
	}
	sort(p.begin(), p.end());
	return p;
}

int main() {
	int N; cin >> N;
	vector<int> a(N), b(N);
	rep(i, N) scanf("%d", &a[i]);
	rep(i, N) scanf("%d", &b[i]);
	if (N % 2 == 0) a.pop_back(), b.pop_back();
	vector<int> p = solve(a, b);
	if (N % 2 == 0) p.push_back(N - 1);
	cout << p.size() << endl;
	for (int i: p) printf("%d ", i + 1);
	cout << endl;
}