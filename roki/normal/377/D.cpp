#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cassert>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9);
const li INF64 = li(1e18);

int n;
const int N = 300000 + 5;
vector<pair<int, pt> > q[N];
int A[100005], B[100005], C[100005];

bool read() {
    if (scanf("%d", &n) != 1)
        return false;
    //n = 100000;
    forn (i, n)
    {
        scanf("%d%d%d", &A[i], &B[i], &C[i]);
        //A[i] = B[i] = C[i] = 300000;
        q[A[i]].pb(mp(1, mp(B[i], C[i])));
        q[B[i] + 1].pb(mp(-1, mp(B[i], C[i])));
    }
}

pt best[4 * N];
int add[4 * N];

void push(int id, int l, int r)
{
    if(id >= 4 * N)
        return;
    best[id].ft += add[id];
    if (l != r)
    {
        add[id * 2 + 1] += add[id];
        add[id * 2 + 2] += add[id];
    }
    add[id] = 0;
}

void upd(int id, int l, int r, int lf, int rg, int d)
{
    if (lf > r || rg < l)
        return;
    push(id, l, r);
    if (l == lf && r == rg)
    {
        add[id] += d;
        push(id, l, r);
        return;
    }

    if (l == r)
        exit(0);

    int mid = (r + l) >> 1;

    if (lf <= mid)
        upd(2 * id + 1, l, mid, lf, min(mid, rg), d);
    if (mid + 1 <= rg)
        upd(2 * id + 2, mid + 1, r, max(lf, mid + 1), rg, d);

    push(2 * id + 1, l, mid);
    push(2 * id + 2, mid + 1, r);

    best[id] = max(best[2 * id + 1], best[2 * id + 2]);
}

void init(int id, int l, int r)
{
    if(id >= 4 * N)
        return;
    best[id] = mp(0, l);
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    init(2 * id + 1, l, mid);
    init(2 * id + 2, mid + 1, r);
}

void solve() {
    init(0, 0, N - 1);

    int ans = 0;
    pt lr = mp(0, 0);
    int it = 0;
    
    forn (i, N)
    {
        forn (j, q[i].size())
            upd(0, 0, N - 1, q[i][j].sc.ft, q[i][j].sc.sc, q[i][j].ft);
        if (best[0].ft > ans)
            ans = best[0].ft, lr = mp(i, best[0].sc);
    }

    cout << ans << endl;
    pt lr2 = mp(0, INF);
    vector<int> answer;
    forn (i, n)
        if (A[i] <= lr.ft && lr.sc <= C[i] && lr.ft <= B[i] && B[i] <= lr.sc)
        {
            answer.pb(i + 1);
            lr2.ft = max(lr2.ft, A[i]);
            lr2.sc = min(lr2.sc, C[i]);
        }

    //assert(lr2.ft <= lr.ft && lr2.sc >= lr.sc);

    forn (i, ans)
    {
        //assert(B[answer[i] - 1] >= lr2.ft && B[answer[i] - 1] <= lr2.sc);
        cout << answer[i] << ' ';
    }
    cout << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
        read();
        solve();

    return 0;
}