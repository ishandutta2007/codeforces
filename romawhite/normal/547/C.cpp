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
const int MAX = 500007;
const int MAX2 = 2000;
const int BASE = 1000000000;

int p[MAX];
int g[MAX];
vector<pair<int,int> > a[MAX];

int b[MAX];
int c[MAX];
bool d[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);

    for(int i = 2; i * i < MAX; ++i)
        if (!p[i])
            for(int j = i * i ; j < MAX; j += i)
                if (!p[j])
                    p[j] = i;

    g[1] = 1;
    for(int i = 2; i < MAX; ++i)
    {
        if (p[i] == 0)
        {
            g[i] = -1;
            p[i] = i;
        }
        else
        {
            int x = i / p[i];
            if (x % p[i] != 0 && g[x] != 0) g[i] = -g[x];
        }
    }


    for(int i = 1; i < MAX; ++i)
        if (g[i] != 0)
            for(int j = i; j < MAX; j += i)
                a[j].push_back(MP(i, g[i]));

    int n , m;
    cin >> n >> m;
    FOR(i,0,n)
    {
        scanf("%d" , &b[i]);
    }

    Int res = 0;
    FOR(i,0,m)
    {
        int x;
        scanf("%d" , &x);
        --x;
        int y = b[x];
        if (!d[x])
        {
            FOR(i,0,a[y].size())
            {
                res += c[a[y][i].first] * a[y][i].second;
                c[a[y][i].first]++;
            }
        }
        else
        {
            FOR(i,0,a[y].size())
            {
                c[a[y][i].first]--;
                res -= c[a[y][i].first] * a[y][i].second;
            }
        }
        /*FOR(i,1,10)
        {
            cout << c[i] << ' ' ;
        }*/
        //cout << endl;
        d[x] ^= 1;
        printf("%I64d\n", res);
    }


    return 0;
}