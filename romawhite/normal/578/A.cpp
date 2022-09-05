#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
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

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 10007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int main()
{
    //freopen("in.txt", "r", stdin);

    int a , b;
    cin >> a >> b;

    if (b > a)
    {
        cout << -1 << endl;
        return 0;
    }

    int k = (a - b) / (2 * b);

    double x1 , res = 2e47;

    if (k)
    {
        x1 = 0.5 * (a - b) / k;
    }
    else
    {
        if (a == b) x1 = a;
        else x1 = 1e48;
    }
    res = min(res , x1);
    int k2 = a / b - 1;
    if (k2 >= 0)
    {
        k2 /= 2;
        double x2 = 0.5 * (a + b) / (k2 + 1);
        res = min(res , x2);
    }

    if (res > 1e17)
    {
        cout << -1 << endl;
        return 0;
    }

    printf("%.12f\n" , res);

    return 0;
}