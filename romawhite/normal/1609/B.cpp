#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>  
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 300007;
const int MOD = 1000000007;

int n, q;
string s;

bool f(int i) {
	if (i < 0 || i >= n - 2) {
		return false;
	}
	if (s.substr(i, 3) == "abc")
		return true;
	return false;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> q;
	cin >> s;
	
	int res = 0;
	FOR(i,0,n - 2) {
		res += f(i);
	}

	FOR(i,0,q) {
		int idx;
		char ch;
		cin >> idx >> ch;
		idx --;
		res -= f(idx - 2) + f(idx - 1) + f(idx);
		s[idx] = ch;
		res += f(idx - 2) + f(idx - 1) + f(idx);
		cout << res << endl;
	}
	
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}