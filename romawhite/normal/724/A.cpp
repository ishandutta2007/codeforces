#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:64000000")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
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
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 100007;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int f(string s)
{
	if (s[0] == 'm') return 0;
	if (s[0] == 't' && s[1] == 'u') return 1;
	if (s[0] == 'w') return 2;
	if (s[0] == 't' && s[1] == 'h') return 3;
	if (s[0] == 'f') return 4;
	if (s[0] == 's' && s[1] == 'a') return 5;
	if (s[0] == 's' && s[1] == 'u') return 6;


}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	string s , t;
	cin >> s >> t;
	int a = f(s);
	int b = f(t);
	if (b == a || b == (a + 2) % 7 || b == (a + 3) % 7)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

    return 0;
}