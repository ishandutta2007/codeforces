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
#define all(a) a.begin(),a.end()

typedef long long li;
typedef double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

#define sqr(n) ((n) * (n))

int n;
const int N = 100005;
int a[N];

bool read() 
{
    if (!(cin >> n))
        return false;
    forn (i, n)
        cin >> a[i];
    forn (i, n)
        a[i]--;
    return true;
}

int s[N];

int win(int l, int r, int t)
{
    int ca = s[r] - s[l];
    int cb = (r - l) - ca;
    if (ca >= t)
        return 1;
    if (cb >= t)
        return 2;
    return 0;
}

vector<int> x;

void solve() 
{
    forn (i, n)
        s[i + 1] = s[i] + a[i];

    vector<pt> ans;

    for (int t = 1; t <= n; ++t)
    {
        int l = 0;
        x.clear();
        while (l < n)
        {
            int lf = -1, rg = n - l - 1;
            while(rg - lf > 1)
            {
                int mid = (lf + rg) >> 1;
                if (win(l, l + mid + 1, t))
                    rg = mid;
                else
                    lf = mid;
            }
            x.pb(win(l, l + rg + 1, t));
            l += rg + 1;
        }
        int cnt1 = 0, cnt2 = 0;
        forn (j, x.size())
            if (x[j] == 1)
                cnt1++;
            else
                cnt2++;
        if (cnt1 > cnt2 && x.back() == 1)
            ans.pb(mp(cnt1, t));
        if (cnt2 > cnt1 && x.back() == 2)
            ans.pb(mp(cnt2, t));
    }

    sort(all(ans));

    cout << ans.size() << endl;

    forn (i, ans.size())
        cout << ans[i].ft << ' ' << ans[i].sc << endl;
}

int main() 
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    while(read())   
        solve();

    return 0;
}