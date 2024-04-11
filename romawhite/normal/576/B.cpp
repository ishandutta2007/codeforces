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
const int MAX = 100007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int p[MAX];
bool u[MAX];

int main()
{

    //freopen("in.txt", "r", stdin);

    int n;
    cin >> n;
    FOR(i,0,n)
    {
        scanf("%d" , &p[i]);
        --p[i];
    }

    FOR(i,0,n)
    {
        if (p[i] == i)
        {
            printf("YES\n");
            FOR(j,0,n)
                if (i != j)
                {
                    printf("%d %d\n" , i + 1 , j + 1);
                }
            return 0;
        }
    }

    FOR(i,0,n)
    {
        if (p[p[i]] == i)
        {
            int j = p[i];
            u[i] = 1;
            u[j] = 1;
            bool ok = 1;
            vector<pair<int,int> > e;
            e.push_back(MP(i, j));
            FOR(t,0,n)
            {
                if (u[t]) continue;
                int v = t;
                int c = 0;
                while (v != t || c == 0)
                {
                    u[v] = 1;
                    ++c;
                    if (c % 2 == 1) e.push_back(MP(i, v));
                    else e.push_back(MP(j , v));
                    v = p[v];
                }
                if (c % 2 == 1) ok = 0;
            }
            if (ok)
            {
                cout << "YES" << endl;
                FOR(i,0,e.size())
                {
                    printf("%d %d\n" , e[i].first + 1 , e[i].second + 1);
                }
            }
            else
            {
                cout << "NO" << endl;
            }
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}