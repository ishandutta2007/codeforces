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
vector<int> a;

inline bool read()
{
    if(!(cin >> n))
        return false;
    a.resize(n);
    forn (i, n)
        cin >> a[i];
    return true;
}

inline void solve()
{
    sort(a.begin(), a.end());
    int ans = 0;
    forn (i, n)
        ans += a[i];
    if(ans % 2 == 0)
        forn (i, n)
        if(a[i] % 2 == 1)   
        {
            cout << ans - a[i];
            return;
        }
    if(ans % 2 == 1)
        cout << ans;
    else
        cout << 0;
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