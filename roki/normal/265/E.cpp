#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
#include<ctime>
#include<unordered_set>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, q;
int v[100000];
int c[100000];

bool read()
{
    if (!(cin >> n >> q))
        return false;
    forn (i, n)
        cin >> v[i];
    forn (i, n)
        cin >> c[i];
    return true;
}

void solve()
{
    vector<li> dp(100000, -1e15);
    forn (i, q)
    {
        int firstMaxPos = 0, secondMaxPos = 1;
        forn (j, 1e5)
            dp[j] = -1e15;
        li a, b;
        cin >> a >> b;
        forn (i, n)
        {
            li val1 = firstMaxPos == c[i] - 1 ? dp[secondMaxPos] : dp[firstMaxPos];
            li val2 = dp[c[i] - 1];
            val1 += v[i] * b;
            val1 = max(val1, v[i] * b);
            if (val2 == -1e15)
                val2 = v[i] * b;
            else
                val2 += v[i] * a;
            dp[c[i] - 1] = max(dp[c[i] - 1], max(val1, val2));
            if (dp[c[i] - 1] >= dp[firstMaxPos] && c[i] - 1 != firstMaxPos)
                secondMaxPos = firstMaxPos, firstMaxPos =  c[i] - 1;
            else
                if (dp[c[i] - 1] > dp[secondMaxPos] && c[i] - 1 != firstMaxPos)
                    secondMaxPos = c[i] - 1;
        }
        cout << max(0LL, dp[firstMaxPos]) << endl;
    }
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}