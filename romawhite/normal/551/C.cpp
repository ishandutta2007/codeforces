#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:32777216")
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

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int n, m;
vector<int> a;

bool F(Int X)
{
    int cnt = m;
    Int x = (X + m - 1) / m;
    if (x - n + 1 <= 0) return 0;
    FOR(i,0,n)
    {
        X -= a[i];
        if (X < 0) return 0;
        X -= (X + x - i - 1) / (x - i);
    }
    return 1;
}

int main()
{
    //freopen("in.txt" , "r", stdin);


    cin >> n >> m;
    a.resize(n);

    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
    }
    while (a.back() == 0) a.pop_back();
    n = a.size();

    Int L = 0;
    Int R = 1LL * INF * INF;
    while (R - L > 1)
    {
        Int X = (L + R) / 2;
        if (F(X)) R = X;
        else L = X;
    }
    if (F(L)) R = L;
    //cout << R << endl;
    cout << (R + m - 1) / m + 1 << endl;

    return 0;
}