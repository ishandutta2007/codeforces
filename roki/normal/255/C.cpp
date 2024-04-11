#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
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

int dp[4000][4000];

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    map<int, int> m;
    int ans = 0;
    forn (i, n)
    {
        cin >> a[i];
        m[a[i]]++;
        ans = max(ans, m[a[i]] - 1);     
        s.insert(a[i]);
    }
    vector<int> b;
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
        b.pb(*it);
    for(int i = 0; i < n; ++i)
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    forn (i, n)
        forn (j, i)
        {
            if(a[i] == a[j])
                continue;
            dp[a[i]][a[j]] = dp[a[j]][a[i]] + 1;
            ans = max(ans, dp[a[i]][a[j]]);
        }
    cout << ans + 1;
    return 0;
}