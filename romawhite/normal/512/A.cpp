

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:128777216")
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
#define MANY 18000000000000000000ull

typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 64;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;
const int CNT = 20;

bool a[107];

int g[107][107];
string s[107];

vector<int> order;
bool used[27];

void dfs(int v)
{
    used[v] = 1;
    FOR(i,0,26)
    {
        if (!used[i] && g[v][i])
        {
            dfs(i);
        }
    }
    order.push_back(v);
}

int main()
{

   //freopen("in.txt", "r", stdin);

    int n;
    cin >> n;

    FOR(i,0,n)
    {
        cin >> s[i];
    }

    bool ok = 1;

    FOR(j,0,107)
    {
        FOR(i,0,n - 1)
        {
            if (j < s[i].size() && j >= s[i + 1].size() && a[i] == 0)
            {
                ok = 0;
            }
            if (j < s[i].size() && j < s[i + 1].size() && a[i] == 0)
            {
                if (s[i][j] != s[i + 1][j])
                {
                    g[s[i][j] - 'a'][s[i + 1][j] - 'a'] = 1;
                    a[i] = 1;
                }
            }
        }
    }
    FOR(i,0,26)
    {
        if (!used[i])
        {
            dfs(i);
        }
    }
    reverse(ALL(order));
    FOR(i,0,26)
    {
        FOR(j,i + 1, 26)
        {
            if (g[order[j]][order[i]])
            {
                ok = 0;
            }
        }
    }
    if (!ok)
    {
        cout << "Impossible\n" << endl;
    }
    else
    {
        FOR(i,0,26)
        {
            cout << (char)('a' + order[i]);
        }
        cout << endl;
    }

    return 0;
}