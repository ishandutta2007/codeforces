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

const int INF = int(1e9) + 6;
const li INF64 = li(1e18);
const ld EPS = 1e-9;

#define sqr(n) ((n) * (n))

int n, m;
const int N = 100005;

pair<pt, pt> a[N];
pair<pt, pt> b[N];

bool read() 
{
    if (!(cin >> n))
        return false;
    forn (i, n)
    {
        a[i].sc.ft = i;
        cin >> a[i].ft.ft >> a[i].ft.sc;
    }
    cin >> m;
    forn (i, m)
    {
        cin >> b[i].ft.ft >> b[i].ft.sc >> b[i].sc.ft;
        b[i].sc.sc = i;
    }
    return true;
}

bool cmp(pair<pt, pt> &a, pair<pt, pt> &b)
{
    if (a.ft.ft != b.ft.ft)
        return a.ft.ft < b.ft.ft;
    return a.ft.sc > b.ft.sc;
}

bool can(pt &a, pt &b)
{
    return b.ft <= a.ft && a.sc <= b.sc;
}

void solve() 
{
    sort(a, a + n, cmp);
    sort(b, b + m, cmp);

    vector<int> ans(n);
    int l = 0;

    set<pt> go;
    set<pt> er;

    forn (i, n)
    {
        while(!go.empty() && go.begin()->ft < a[i].ft.ft)
            go.erase(go.begin());
        while(l < m && b[l].ft.ft <= a[i].ft.ft)
        {
            go.insert(mp(b[l].ft.sc, l));
            l++;
        }

        if (go.size())
        {
            set<pt>::iterator it = go.lower_bound(mp(a[i].ft.sc, -INF));
            if (it != go.end())
            {
                int v = it->sc;
                ans[a[i].sc.ft] = b[v].sc.sc;
                b[v].sc.ft--;
                if (b[v].sc.ft == 0)
                    go.erase(it);
                continue;
            }
        }
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    forn (i, n)
        cout << ans[i] + 1 << ' ';
    cout << endl;
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