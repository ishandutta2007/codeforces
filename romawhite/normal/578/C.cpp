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
const int MAX = 200007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int a[MAX];
int n;

double s[MAX];

double F(double x)
{
    double res = 0;
    double cur = 0;
    FOR(i,0,n)
    {
        cur += a[i] - x;
        res = max(res , cur);
        if (cur < 0) cur = 0;
    }
    cur = 0;
    FOR(i,0,n)
    {
        cur += x - a[i];
        res = max(res , cur);
        if (cur < 0) cur = 0;
    }
    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    cin >> n;
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
    }

    s[0] = 0;
    FOR(i,1,n + 1)
    {
        s[i] = s[i - 1] + a[i - 1];
    }

    double L = -1e9;
    double R = 1e9;

    //cout << F(2) << endl;

    FOR(it,0,147)
    {
        double M1 = L + (R - L) / 3;
        double M2 = L + 2 * (R - L) / 3;
        if (F(M1) < F(M2)) R = M2;
        else L = M1;
    }

    //cout << L << endl;

    printf("%.10f\n" , F(L));

    return 0;
}