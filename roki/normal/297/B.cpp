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

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, m, k;
vector<int> a;
vector<int> b;

bool read()
{
    if(!(cin >> n >> m >> k))
        return false;
    a.resize(n);
    b.resize(m);
    forn (i, n)
        cin >> a[i];
    forn (i, m)
        cin >> b[i];
    return true;
}

void solve()
{
    int l = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    forn (i, n)
    {
        while(l < m && a[i] > b[l])
            l++;
        if(n - i > m - l)
        {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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