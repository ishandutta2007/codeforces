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
const int MAX = 50007;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;

double vm(double x1, double y1, double x2, double y2)
{
    return x1 * y2 - x2 * y1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    #endif

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int n;
    cin >> n;

    int res = 0;

    FOR(i,0,n)
    {
        int a ,b , c;
        cin >> a >> b >> c;

        double tx , ty;
        if (b != 0)
        {
            tx = - INF;
            ty = (-c - a * tx) / b;
        }
        if (a != 0)
        {
            ty = -INF;
            tx = (-c - b * ty) / a;
        }

        if (vm(-b, a, x1 - tx, y1 - ty) * vm(-b, a, x2 - tx, y2 - ty) < 0)
        {
            ++res;
        }

    }

    cout << res << endl;

    return 0;
}