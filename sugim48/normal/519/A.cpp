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
	int w = 0, b = 0;
	for (int i = 0; i < 8; i++) {
		string s; cin >> s;
		for (int j = 0; j < 8; j++)
			switch (s[j]) {
			case 'Q': w += 9; break;
			case 'R': w += 5; break;
			case 'B': w += 3; break;
			case 'N': w += 3; break;
			case 'P': w += 1; break;
			case 'q': b += 9; break;
			case 'r': b += 5; break;
			case 'b': b += 3; break;
			case 'n': b += 3; break;
			case 'p': b += 1; break;
			}
	}
	if (w > b) cout << "White" << endl;
	if (w < b) cout << "Black" << endl;
	if (w == b) cout << "Draw" << endl;
}