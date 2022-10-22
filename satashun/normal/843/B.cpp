#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

ll rand_int(ll l, ll r) {  //[l,r]
    static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}

template <class T>
vector<T> random_perm(vector<T> vec) {  // FisherYates
    vector<T> res;
    rep(i, vec.size()) {
        res.pb(vec[i]);
        int j = rand_int(0, i);
        swap(res[j], res[i]);
    }
    return res;
}

pii ask(int i) {
    printf("? %d\n", i + 1);
    fflush(stdout);
    int val, nxt;
    scanf("%d %d", &val, &nxt);
    if (nxt != -1) --nxt;
    return mp(val, nxt);
}

void answer(int x) {
    printf("! %d\n", x);
    exit(0);
}

const int INF = TEN(9) * 2;

int main() {
    // cin.tie(nullptr);
    // ios::sync_with_stdio(false);

    int n, s, x;
    scanf("%d%d%d", &n, &s, &x);
    --s;

    int rem = 1999;
    V<int> val(n, -1), nx(n, -2);

    V<int> pm;
    rep(i, n) if (i != s) pm.pb(i);
    pm = random_perm(pm);

    int now = 0;

    rep(i, min(1000, n)) {
        int v;
        if (i == 0) {
            v = s;
        } else {
            v = pm[now++];
        }

        pii p = ask(v);
        val[v] = p.fi;
        nx[v] = p.se;
    }

    int maxi = -1, p = -1;
    rep(i, n) if (val[i] != -1 && val[i] <= x && val[i] >= maxi) {
        maxi = val[i];
        p = i;
    }

    if (p == -1) {
        int ans = INF;
        rep(i, n) if (val[i] != -1 && val[i] >= x) { chmin(ans, val[i]); }
        answer(ans);
    }

    int ans = -1;
    while (p != -1) {
        pii nx = ask(p);
        if (nx.fi >= x) {
            ans = nx.fi;
            break;
        }
        p = nx.se;
    }
    answer(ans);
    return 0;
}