#define _CRT_SECURE_NO_WARNINGS
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
const int MAX = 300007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

Int res = 0;
int a[MAX];

int cnt1[1000007];
int cnt2[1000007];

int k;

void solve(int l, int r)
{
    if (l == r) return;
    int m = (l + r) / 2;
    solve(l, m);
    solve(m + 1 , r);

    int i = m;
    int j = m + 1;
    int M1 = 0;
    int M2 = 0;
    int s1 = 0;
    int s2 = 0;
    while (i >= l || j <= r)
    {
        if (i < l)
        {
            s2 = (s2 + a[j]) % k;
            M2 = max(M2 , a[j]);
            int add = (k - s2 + M2) % k;
            res += cnt1[add];
            ++j;
            cnt2[s2]++;
            continue;
        }
        if (j > r)
        {
            s1 = (s1 + a[i]) % k;
            M1 = max(M1 , a[i]);
            int add = (k - s1 + M1) % k;
            res += cnt2[add];
            --i;
            cnt1[s1]++;
            continue;
        }
        if (max(M1, a[i]) <= max(M2, a[j]))
        {
            M1 = max(M1 , a[i]);
            s1 = (s1 + a[i]) % k;
            int add = (k - s1 + M1) % k;
            res += cnt2[add];
            --i;
            cnt1[s1]++;
        }
        else
        {
            s2 = (s2 + a[j]) % k;
            M2 = max(M2 , a[j]);
            int add = (k - s2 + M2) % k;
            res += cnt1[add];
            ++j;
            cnt2[s2]++;
        }
    }
    s1 = 0;
    i = m;
    while (i >= l)
    {
        s1 = (s1 + a[i]) % k;
        cnt1[s1]--;
        --i;
    }
    s2 = 0;
    j = m + 1;
    while(j <= r)
    {
        s2 = (s2 + a[j]) % k;
        cnt2[s2]--;
        ++j;
    }
   /* FOR(i,0,k)
    {
        if (cnt1[i] != 0 || cnt2[i] != 0)
        {
            cout << l << ' ' <<r << ' ' << cnt1[i] << ' ' << cnt2[i] << endl;
            //throw -1;
        }
    }*/
}

int main()
{
   // freopen("in.txt","r",stdin);

    int n;
    cin >> n >> k;
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
    }

    solve(0, n - 1);

    cout << res << endl;

    return 0;
}