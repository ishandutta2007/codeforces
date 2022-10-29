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
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n;
int a[5000];

bool read()
{
    if (!(cin >> n))
        return false;
    forn (i, n)
        cin >> a[i];
    return true;
}

vector<int> pos[5000];

int getCnt(int v, int i, int j)
{
    int l = lower_bound(pos[v].begin(), pos[v].end(), i) - pos[v].begin();
    int r = lower_bound(pos[v].begin(), pos[v].end(), j) - pos[v].begin();
    return max(r - l - 1 + 1 * (pos[v][l] > i ? 1 : 0), 0);
}

void solve()    
{
    vector<int> inv(n);
    forn (i, n)
        for (int j = 0; j < n; ++j)
        {
            if (a[i] >= a[j])
            {
                if (j > i)
                    inv[i]++;
                pos[i].pb(j);
            }
        }
    int ans1 = 0, ans2 = 1;
    forn (i, n)
        ans1 += inv[i];
    int sum = ans1;
    forn (i, n)
        for (int j = i + 1; j < n; ++j)
        {
            int cntI = getCnt(i, i, j);     
            int cntJ = getCnt(j, i, j);     
            int cur = sum - cntI + j - i - 1 - cntI + 1 * (a[j] > a[i] ? 1 : -1);
            cur += cntJ - (j - i - 1 - cntJ);
            if (cur < ans1)
                ans1 = cur, ans2 = 0;
            if (cur == ans1)
                ans2++;
        }
        cout << ans1 << ' ' << ans2 << endl;
}
    
int main()
{
#ifdef SU6
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
        read();
        solve();
    return 0;
}