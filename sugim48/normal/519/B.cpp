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
	int n; cin >> n;
	ll A = 0, B = 0, C = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		A += a;
	}
	for (int i = 0; i < n - 1; i++) {
		int b; cin >> b;
		B += b;
	}
	for (int i = 0; i < n - 2; i++) {
		int c; cin >> c;
		C += c;
	}
	cout << A - B << endl;
	cout << B - C << endl;
}