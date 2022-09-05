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
#include <fstream>
#include <time.h>
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
#define y0 gfdssdfer
#define y1 wetgwervbwqr

typedef long long Int;

const int MAX = 100007;
const int MOD = 1000000007;

int brute(int a, int b)
{
    Int res = 0;
    FOR(i,1,b)
    {
        FOR(k,1,a + 1)
        {
            res += b * k * i + i;
        }
    }
    return res % MOD;
}

int main()
{
    //freopen("in.txt" , "r" , stdin);

    int a, b;
    cin >> a >> b;

    Int res = 0;

    FOR(i,1,b)
    {
        res += 1LL * a * (a + 1) / 2 % MOD * i % MOD * b % MOD;
        res += 1LL * a * i % MOD;
        res %= MOD;
    }
    //cout << brute(a, b) << endl;
    cout << res << endl;

    return 0;
}