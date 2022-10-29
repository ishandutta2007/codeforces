#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define itr(x) x::iterator

typedef vector < int > vi;
typedef vector < vi > v2i;
typedef long long ll;

#ifdef _DEBUG
#define endline endl
#else
#define endline "\n"
#endif

ll
gcd(ll a, ll b)
{
    ll tmp = 0LL;
    while (b != 0LL) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

ll
lcm(ll a, ll b)
{
#ifdef _DEBUG
    cerr << "a " << a << " " << b << " " << a * (b / gcd(a, b)) << endline;
#endif
    return a * (b / gcd(a, b));
}

vi a;
v2i g;
vector < ll > mult;
vector < bool > used;
vector < bool > isList;
vi cnt;
ll sum;
int n;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void
dfs(int x)
{
    used[x] = true;
    ll cur_lcm = 1LL;
    int cnt1 = sz(g[x]);
    vi tmp;
    for (int i = 0; i < cnt1; ++i) {
        int to = g[x][i];
        if (!used[to]) {
            dfs(to);
            cur_lcm = lcm(cur_lcm, mult[to]);
            tmp.pb(to);
            if (cur_lcm > sum) {
                mult[x] = sum + 1;
                cnt[x] = 0;
                return;
            }
        }
    }
    mult[x] = max(1LL, cur_lcm * sz(tmp));
#ifdef _DEBUG
    cerr << cur_lcm << " " << sz(tmp) << endline;
#endif
    cnt1 = sz(tmp);
    cnt[x] = (tmp.empty()) ? a[x] : sum;
#ifdef _DEBUG
    cerr << "mult[" << x << "] = " << mult[x] << endline;
#endif
    for (int i = 0; i < cnt1; ++i) {
        int to = tmp[i];
#ifdef _DEBUG
        cerr << cnt[to] << " " << cur_lcm << " " << mult[to] << endline;
#endif
        cnt[x] = min(cnt[x], (int) (cnt[to] / (cur_lcm / mult[to])));
    }
#ifdef _DEBUG
    cerr << "cnt[" << x << "] = " << cnt[x] << endline;        
#endif
}

#ifdef _DEBUG
bool
#else
void
#endif
input_data()
{
#ifdef _DEBUG
    if (!(cin >> n)) {
        return false;
    }
#else
    cin >> n;
#endif
    g.resize(n + 1);
    used.assign(n + 1, false);
    cnt.assign(n + 1, 0);
    mult.assign(n + 1, 0LL);
    a.assign(n + 1, 0);
    sum = 0LL;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i < n; ++i) {
        int from, to;
        cin >> from >> to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(1);
    ll ans = sum - mult[1] * cnt[1];
    cout << ans << endline;
#ifdef _DEBUG
    return true;
#endif
}

void
calc()
{
}


int
main(void)
{
#ifndef _DEBUG
    ios_base::sync_with_stdio(false);
    input_data();
#else
    while (input_data()) {
#endif
    calc();
#ifdef _DEBUG
    }
#endif
    return 0;
}