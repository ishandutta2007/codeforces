

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:128777216")
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
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define free adsgasdg


typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 7801;
const int MAX2 = 200000;
const int BASE = 1000000007;
const int MOD = 1000000007;
const int CNT = 1000;

int main()
{
  //  freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    if (n > k)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }

    return 0;
}