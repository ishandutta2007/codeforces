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

int n;
int a[100], b[100];

bool read()
{
    if(!(cin >> n))
        return false;
    forn (i, n)
        cin >> a[i] >> b[i];
    return true;
}

void solve()
{
    bool bad = false;
    forn (i, n)
        forn (j, n)
            if(a[i] + b[i] == a[j] && a[j] + b[j] == a[i])
                bad = true;
    if(bad)
        cout << "YES";
    else
        cout << "NO";
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