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
const int MAX = 100007;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;

int a[MAX];
int c[MAX];
int C[MAX];

int f(vector<int> b)
{
    FILL(c,0);
    FILL(C,0);
    FOR(i,0,b.size())
    {
        c[b[i]]++;
    }

    bool odd = b.size() % 2;
    int mid = b.size() / 2;
    int val = -1;
    if (odd)
    {
        FOR(i,0,MAX)
        {
            if (c[i] % 2 == 1)
            {
                val = i;
                break;
            }
        }
    }

    RFOR(i,b.size() , 0)
    {
        if (odd && i == mid)
        {
            if (b[i] != val)
            {
                return i;
            }
            continue;
        }
        if (i >= mid)
        {
            C[b[i]]++;
            if (C[b[i]] > c[b[i]] / 2)
            {
                return i;
            }
        }
        else
        {
            if (b[i] != b[b.size() - 1 - i])
            {
                return i;
            }
        }
    }


}

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt" , "w" , stdout);
    #endif

    int n;
    cin >> n;
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
        c[a[i]]++;
    }

    int cnt = 0;
    FOR(i,0,MAX)
    {
        cnt += c[i] % 2;
    }

    if (cnt > 1)
    {
        cout << 0 << endl;
        return 0;
    }

    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        if (a[l] != a[r])
        {
            break;
        }
        ++l;
        --r;
    }
    if (l > r)
    {
        cout << 1LL * n * (n + 1) / 2 << endl;
        return 0;
    }

    Int res = 1LL * (l + 1) * (l + 1);

    vector<int> b;
    FOR(i,l,r + 1)
    {
        b.push_back(a[i]);
    }

    int x = f(b);
    res += 1LL * (b.size() - 1 - x) * (l + 1);
    //cout << x << ' ' << l << endl;

    reverse(ALL(b));
    x = f(b);
    res += 1LL * (b.size() - 1 - x) * (l + 1);
    //cout << x << ' ' << l << endl;

    cout << res << endl;

    return 0;
}