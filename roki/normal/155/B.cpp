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

int n;
pair<int, int> a[1000];

bool read()
{
    if (!(cin >> n))
        return false;
    forn (i, n)
        cin >> a[i].first >> a[i].second;
    return true;
}

bool cmp (pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    return a.first > b.first;
}

void solve()
{
    int sum = 1;
    sort (a, a + n, cmp);
    int l = 0;
    int ans = 0;
    while (l < sum && l < n)
    {
        ans += a[l].first;
        sum += a[l].second;
        l++;
    }
    cout << ans << endl;
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