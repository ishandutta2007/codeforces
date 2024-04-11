#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <fstream>
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

int main() {
	ll n, m; cin >> n >> m;
	vector< vector<int> > B(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> B[i][j];
	vector< vector<int> > A(n, vector<int>(m, 1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			for (int _i = 0; _i < n; _i++) A[i][j] &= B[_i][j];
			for (int _j = 0; _j < m; _j++) A[i][j] &= B[i][_j];
		}
	vector< vector<int> > _B(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			for (int _i = 0; _i < n; _i++) _B[i][j] |= A[_i][j];
			for (int _j = 0; _j < m; _j++) _B[i][j] |= A[i][_j];
		}
	if (B == _B) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << A[i][j] << ' ';
			cout << endl;
		}
	}
	else cout << "NO" << endl;
}