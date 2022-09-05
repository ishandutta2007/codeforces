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
const int MAX = 500007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

const int K = 700;

Int add[MAX / K + 7];
vector<pair<Int,int> > a[MAX / K + 7];

int main()
{
    //freopen("in.txt" , "r", stdin);

    int n , q;
    cin >> n >> q;
    FOR(i,0,n)
    {
        int x;
        scanf("%d" , &x);
        a[i / K].push_back(MP(x, i));
    }

    FOR(i,0,n / K + 1)
    {
        sort(ALL(a[i]));
    }

    FOR(i,0,q)
    {
        int t;
        scanf("%d" , &t);
        if (t == 1)
        {
            int l , r, x;
            scanf("%d%d%d" , &l , &r, &x);
            --l;--r;
            for(int j = 0; j < n; j += K)
            {
                if (j >= l && min(n - 1, j + K - 1) <= r)
                {
                    add[j / K] += x;
                    continue;
                }
                if (min(n - 1, j + K - 1) < l) continue;
                if (j > r) continue;
                FOR(t,0,a[j / K].size())
                {
                    if (a[j / K][t].second >= l && a[j / K][t].second <= r)
                        a[j / K][t].first += x;
                }
                sort(ALL(a[j / K]));
            }
        }
        else
        {
            int y;
            scanf("%d" , &y);
            int l = INF;
            int r = -INF;
            Int Y = y;
            FOR(j,0,n / K + 3)
            {
                Y -= add[j];
                int id = lower_bound(ALL(a[j]) , MP(Y,-1)) - a[j].begin();
                if (id < a[j].size() && a[j][id].first == Y)
                {
                    l = min(l, a[j][id].second);
                    r = max(r, a[j][id].second);
                }
                id = lower_bound(ALL(a[j]) , MP(Y,INF)) - a[j].begin() - 1;
                if (id >= 0 && a[j][id].first == Y)
                {
                    l = min(l, a[j][id].second);
                    r = max(r, a[j][id].second);
                }
                Y += add[j];
            }
            int res = r - l;
            res = max(res, -1);
            printf("%d\n" , res);
        }
    }

    return 0;
}