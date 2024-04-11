#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<unordered_set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
#include<ctime>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n;
int a[100000];
int t[100001];

bool read()
{
    if(!(cin >> n))
        return false;
    forn (i, n)
        cin >> a[i];
    return true;
}

void solve()
{
    int ans = n;
    forn (i, n)
    {
        int cur = i;
        if(cur > n / 2 - 1 + (n & 1))
            cur = n - cur - 1;
        if(a[i] > cur)
        {
            t[a[i] - cur]++;
            ans = min(ans, n - t[a[i] - cur]);
        }
    }
    cout << ans << endl;
}

int main() {
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}