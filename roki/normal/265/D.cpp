#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef long long li;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn (k, n)
        cin >> a[k];
    vector<int> dp(n), d(100001, 0);
    sort(a.begin(), a.end());
    int ans = 1;
    forn (i, n)
    {
        dp[i] = 1;
        for (int j = 2; j * j <= a[i]; ++j)
        {
            if(a[i] % j == 0)
            {
                dp[i] = max(dp[i], d[j] + 1);
                dp[i] = max(dp[i], d[a[i] / j] + 1);
            }
        }
        for (int j = 2; j * j <= a[i]; ++j)
        {
            if(a[i] % j == 0)
            {
                d[j] = max(d[j], dp[i]);
                d[a[i] / j] = max(d[a[i]/ j], dp[i]);
            }
        }
        d[a[i]] = max(d[a[i]], dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}