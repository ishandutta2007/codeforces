#define _USE_MATH_DEFINES

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()

typedef long long li;
typedef double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-15;

int n, dif, len;
const int N = 100005;
int a[N];

bool read() {
    
    if (!(cin >> n >> dif>> len))
        return false;
    forn (i, n)
        cin >> a[i];
    return true;
}

int dp[N];
multiset<int> s;
multiset<int> sd;

void solve() {
    forn (i, N)
        dp[i] = -1;

    int l = 0;
    dp[0] = 0;

    forn (i, n)
    {
        s.insert(a[i]);
        if (i - len + 1 >= 0 && dp[i - len + 1] != -1 && l <= i - len + 1)
            sd.insert(dp[i - len + 1]);

        multiset<int>::iterator it = s.end();
        it--;

        int Max = *it;
        while(Max - *s.begin() > dif)
        {
            s.erase(s.find(a[l]));
            if (i - l + 1 >= len && dp[l] != -1)
                sd.erase(sd.find(dp[l]));
            l++;
            it = s.end();
            it--;
            Max = *it;
        }
        if (s.size() >= len && sd.size())
            dp[i + 1] = *sd.begin() + 1;
    }

    cout << dp[n] << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else

#ifdef TASK_NAME
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif

#endif

    while(read())   
        solve();

    return 0;
}