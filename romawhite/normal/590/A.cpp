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
#include <cassert>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 500007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

int a[MAX];
int c[MAX];

int main()
{
    //freopen("in.txt" , "r" , stdin);

    int n;
    cin >> n;
    FOR(i,1,n + 1)
    {
        scanf("%d" , &a[i]);
    }
    a[0] = a[1];
    a[n + 1] = a[n];

    FOR(i,0,n + 2)
    {
        c[i] = a[i];
    }

    vector<PII> b;
    FOR(i,0,n + 1)
    {
        if (a[i] == a[i + 1])
        {
            b.push_back(MP(i, a[i]));
        }
    }
    int res = 0;
    FOR(i,0,b.size() - 1)
    {
        int l = b[i].first;
        int r = b[i + 1].first;
        if (b[i].second != b[i + 1].second)
        {
            int cnt = (r - l - 2) / 2;
            res = max(res , cnt);
            FOR(i,l + 2 , l + 2 + cnt)
                c[i] = c[l];
            FOR(i,l + 2 + cnt , l + 2 + 2 * cnt)
                c[i] = c[r];
        }
        else
        {
            int cnt = (r - l) / 2;
            res = max(res , cnt);
            FOR(i,l,r)
                c[i] = c[l];
        }
    }

    cout << res << endl;
    FOR(i,1,n + 1)
    {
        printf("%d " , c[i]);
    }

    return 0;
}