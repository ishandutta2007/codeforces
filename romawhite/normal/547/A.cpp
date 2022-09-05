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
const int MAX = 1000007;
const int MAX2 = 2000;
const int BASE = 1000000000;

int used[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    int m;
    cin >> m;
    int h1,a1,x1,y1;
    cin >> h1 >> a1 >> x1 >> y1;
    int h2,a2,x2,y2;
    cin >> h2 >> a2 >> x2 >> y2;

    vector<int> A;
    FOR(it,1,2 * m + 47)
    {
        h1 = (1LL * h1 * x1 + y1) % m;
        if (h1 == a1) A.push_back(it);
    }
    vector<int> B;
    FOR(it,1,2 * m + 47)
    {
        h2 = (1LL * h2 * x2 + y2) % m;
        if (h2 == a2) B.push_back(it);
    }

    while (A.size() > 2) A.pop_back();
    while (B.size() > 2) B.pop_back();

    if (A.size() == 0 || B.size() == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    Int res = 1LL * INF * INF;
    FOR(i,0,A.size())
        FOR(j,0,B.size())
            if (A[i] == B[j])
                res = min(res , 1LL * A[i]);
    if (A.size() == 2 && B.size() == 2)
    {
        int A1 = A[0];
        int B1 = A[1] - A[0];
        int A2 = B[0];
        int B2 = B[1] - B[0];
        FOR(it,0,m + 47)
        {
            Int T = A1 + 1LL * it * B1;
            if (T >= A2 && (T - A2) % B2 == 0)
            {
                res = min(res , T);
            }
        }
    }

    if (res == 1LL * INF * INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << res << endl;
    }

    return 0;
}