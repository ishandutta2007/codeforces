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
int a[1000][1000];

bool read()
{
    if(!(cin >> n >> m >> k))
        return false;
    forn (i, n)
        forn (j, m)
        cin >> a[i][j];
    return true;
}

void solve()
{
    int h[1000], w[1000];
    forn (i, 1000)
        h[i] = w[i] = i;
    forn (t, k)
    {
        char c;
        int q, v;
        scanf("\n%c%d%d", &c, &q, &v);
        q--, v--;
        if(c == 'r')
            swap(h[q], h[v]);
        if(c == 'c')
            swap(w[q], w[v]);
        if(c == 'g')
            cout << a[h[q]][w[v]] << endl;
    }
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