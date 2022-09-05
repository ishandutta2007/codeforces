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
#define eps 1e-9
typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 7000;
const int BASE = 1000000000;

int a[2][100007];

int f(int i, int l, int r)
{
    return a[i][r + 1] - a[i][l];
}

int main()
{
    #ifndef ONLINE_JUDGE
      //freopen("in.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    a[0][0] = a[1][0] = 0;

    FOR(i,0,n)
    {
        int x;
        cin >> x;
        a[0][i + 1] = a[0][i];
        a[1][i + 1] = a[1][i];
        a[x - 1][i + 1]++;
    }

    vector<pair<int,int> > res;

    FOR(t,1,n + 1)
    {
        int A = 0;
        int B = 0;
        int last = -1;
        int id = 0;
        while (id < n)
        {
            //cout << id << endl;
            if (f(0,id,n - 1) < t && f(1,id,n - 1) < t) break;
            int L = id;
            int R = n - 1;
            while(R - L > 1)
            {
                int X = (L + R) / 2;
                if (f(0,id,X) < t && f(1,id,X) < t)
                {
                    L = X;
                }
                else
                {
                    R = X;
                }
            }
            if (f(0,id,L) >= t || f(1,id,L) >= t) R = L;
            if (f(0,id,R) == t)
            {
                ++A;
                last = 0;
            }
            else
            {
                ++B;
                last = 1;
            }
            id = R + 1;
        }
        //cout << t << ' ' << id << ' ' << A << ' ' << B << endl;
        if (id == n)
        {
            if (last == 0 && A > B)
            {
                res.push_back(MP(A,t));
            }
            if (last == 1 && A < B)
            {
                res.push_back(MP(B,t));
            }
        }

    }

    sort(ALL(res));

    cout << res.size() << endl;

    FOR(i,0,res.size())
    {
        printf("%d %d\n" , res[i].first, res[i].second);
    }

    return 0;
}