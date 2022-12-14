#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define FOR(i, a, b) for (int _tmp = (b), i = (a); i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < long double, long double > pdd;

int n, a[N], wh[N], b[N];
vector < int > cnt[N];
vector <pair <int, pii> > can;
pair <int,int> t[N<<1];

ll c2n(ll n) {
    return n * (n -1) / 2;
}

pii que(int l, int r) {
    l += n;
    r += n;
    pii ans = mp(1e9, 1e9);
    while (l <= r) {
        if (l & 1) ans = min(ans, t[l++]);
        if (~r & 1) ans = min(ans, t[r--]);
        l /= 2;
        r /= 2;
    }
    return ans;
}

void upd(int p, int v) {
    t[p + n] = mp(v, p);
    p += n;
    for (; p > 1; p /= 2)
        t[p / 2] = min(t[p], t[p ^ 1]);
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
/*
int solve(int l, int r) {
    int ans = 0;
    for (int i = 0; i < l; ++i) {
        for (int j = r + 1; j < n; ++j) {
            ans = max(ans, gcd(a[i], a[j]));
        }
    }
    for (int i = 0; i < l; ++i) {
        for (int j = i + 1; j < l; ++j) {
            ans = max(ans, gcd(a[i], a[j]));
        }
    }
    for (int i = r + 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = max(ans, gcd(a[i], a[j]));
        }
    }
    return ans;
}

int calc() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            res += solve(i, j);
       //     cout << "WHERE: " << i << ' ' << j << ' ' << solve(i, j) << endl;
        }
    }
    return res;
}*/

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    memset(wh, -1, sizeof wh);
    FOR(i, 0, n - 1) {
        a[i] = i + 1;
    }
    srand(time(NULL));
    random_shuffle(a, a + n);
    FOR(i, 0, n - 1) {
        cin >> a[i];
        wh[a[i]] = i;
    }
    FOR(d, 1, N - 1) {
        for (int x = d; x < N; x += d)
            if (wh[x] != -1)
                cnt[d].pb(wh[x]);
    }
    FOR(i, 0, N - 1) {
        int j = N - 1 - i;
        if (cnt[j].size() < 2)
            continue;
        sort(cnt[j].begin(), cnt[j].end());
        if (cnt[j][cnt[j].size() - 2] - 1 >= 0)
            can.pb(mp(j, mp(0, cnt[j][cnt[j].size() - 2] - 1)));
        if (cnt[j][1] + 1 <= n - 1)
            can.pb(mp(j, mp(cnt[j][1] + 1, n - 1)));
        if (cnt[j][0] + 1 <= cnt[j].back() - 1)
            can.pb(mp(j, mp(cnt[j][0] + 1, cnt[j].back() - 1)));
    }
    ll ans = 0;
    FOR(i, 0, n - 1) {
        b[i] = i - 1;
        t[i + n] = mp(b[i], i);
    }
    for (int i = n - 1; i >= 1; --i)
        t[i] = min(t[2 * i], t[2 * i + 1]);
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    long long total = c2n(n + 1) - 3;
    FOR(i, 0, can.size() - 1)
    {
        int nl = can[i].y.x, nr = can[i].y.y, nv = can[i].x;
       /* for (int j = nl; j <= nr; ++j) {
            if (nr > b[j]) {
                ans += (ll)nv * (nr - b[j]);
                b[j] = nr;
            }
        }*/
        while (true) {
            pii f = que(nl, nr);
            if (f.first >= nr)
                break;
            ans += (ll)nv * (nr - f.first);
            total -= nr - f.first;
            upd(f.second, nr);
        }
    }
//    cout << calc() << endl;
    cout << ans << endl;
    return 0;
}