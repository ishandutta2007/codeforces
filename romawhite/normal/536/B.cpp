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
const int MAX = 1000007;
const int MAX2 = 7000;
const int BASE = 1000000000;
const Int INF2 = 10000000000000007LL;
const int MOD = 1000000007;

char s[MAX];
int z[MAX];

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
    #endif

    int n , m;
    cin >> n >> m;
    scanf("%s" , s);
    int N = strlen(s);

    for (int i=1, l=0, r=0; i<N; ++i)
    {
        if (i <= r)
        {
            z[i] = min (r - i + 1, z[i - l]);
        }
        while (i+z[i] < N && s[z[i]] == s[i+z[i]])
        {
            ++z[i];
        }
        if (i+z[i]-1 > r)
        {
            l = i;
            r = i+z[i]-1;
        }
    }

    vector<int> a(m);
    FOR(i,0,m)
    {
        scanf("%d" , &a[i]);
        --a[i];
    }

    Int R = 1;
    int last = 0;
    FOR(i,0,m)
    {
        if (a[i] >= last)
        {
            FOR(j,0,a[i] - last)
            {
                R *= 26;
                R %= MOD;
            }
        }
        else
        {
            int pos = N - (last - a[i]);
            if (pos + z[pos] != N) R = 0;
        }
        last = a[i] + N;
    }

    FOR(i,last, n)
    {
        R *= 26;
        R %= MOD;
    }

    cout << R << endl;

    return 0;
}