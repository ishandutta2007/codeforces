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

const int INF = 1000000000;

set<int> sq;

int main()
{

    FOR(i,0,10000)
        sq.insert(i * i);

    int a,b;
    cin >> a >> b;
    FOR(x,1,a)
    {
        int y2 = a * a - x * x;
        if (sq.find(y2) == sq.end())
            continue;
        int y = sqrt(1.0 * y2) + 0.1;
        if (b * x % a == 0 && b * y % a == 0)
        {
            int x1 = - b * y / a;
            int y1 = b * x / a;
            if (x != x1 && y != y1)
            {
                cout << "YES\n";
                cout << "0 0\n";
                cout << x << ' ' << y << endl;
                cout << x1 << ' ' << y1 << endl;
                return 0;
            }
        }
    }


    cout << "NO\n";

}