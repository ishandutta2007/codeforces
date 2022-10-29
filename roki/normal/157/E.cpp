#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ft first
#define sc second

const int INF = 1e9;

string s;

bool read()
{
    return (cin >> s);
}

const int N = 3000;

int dp[105][N];

void solve() 
{
    int sum = 0;
    forn (i, s.size())
        sum += s[i] - 'a' + 1;

    cout << dp[s.size()][sum] - 1 << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    int t;
    cin >> t;

    int mod = 1e9 + 7;  
    dp[0][0] = 1;
    for (int i = 1; i < 105; ++i)
        for (int j = i; j <= i * 26; ++j)
            for (int lt = 1; lt <= 26; ++lt)
                if (j - lt >= 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - lt]) % mod;

    while(read())
        solve();

    return 0;
}