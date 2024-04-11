/*
    Soheil Mohammadkhani
    I will change this text here when i've got "...":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

//My last try to write a correct lazy propagation :(

struct node {
   ll tag = 0;
   ll min_val = 0;
   ll max_val = 0;
};

node tree[4 * MAXN];
ll a[MAXN] = {0}, i = 0;

void updateX(ll si, ll ss, ll se, ll us, ll ue, ll diff) {
//    if (si * 2 + 2 >= 4 * MAXN) return;
    if (tree[si].tag != 0) {
        tree[si].min_val += tree[si].tag;
        tree[si].max_val += tree[si].tag;
        if (ss != se) {
            tree[si * 2 + 1].tag += tree[si].tag;
            tree[si * 2 + 2].tag += tree[si].tag;
        }

        tree[si].tag = 0;
    }

    if (ss > se || ss > ue || se < us) return;

    if (ss >= us && se <= ue) {
        tree[si].min_val += diff;
        tree[si].max_val += diff;
        if (ss != se) {
            tree[si * 2 + 1].tag += diff;
            tree[si * 2 + 2].tag += diff;
        }
        return;
    }

    int mid = (ss + se) / 2;
    updateX(si * 2 + 1, ss, mid, us, ue, diff);
    updateX(si * 2 + 2, mid + 1, se, us, ue, diff);

    tree[si].max_val = max(tree[2 * si + 1].max_val, tree[2 * si + 2].max_val);
    tree[si].min_val = min(tree[2 * si + 1].min_val, tree[2 * si + 2].min_val);
}

pll MinMaxX(ll ss, ll se, ll qs, ll qe, ll si) {
//    debug(si)
//    debug(ss)
//    debug(se)
    if (tree[si].tag != 0) {
        tree[si].min_val += tree[si].tag;
        tree[si].max_val += tree[si].tag;
        if (ss != se) {
            tree[si * 2 + 1].tag += tree[si].tag;
            tree[si * 2 + 2].tag += tree[si].tag;
        }

        tree[si].tag = 0;
    }

    //BUGGY
    if (ss > se || ss > qe || se < qs) return {INF, -INF};
    if (ss >= qs && se <= qe) return {tree[si].min_val, tree[si].max_val};

    ll mid = (ss + se) / 2;
    pll q1 = MinMaxX(ss, mid, qs, qe, 2 * si + 1);
    pll q2 = MinMaxX(mid + 1, se, qs, qe, 2 * si + 2);
    return {min(q1.X, q2.X), max(q1.Y, q2.Y)};
}

void update(ll n, ll us, ll ue, ll diff) {
    updateX(0, 0, n - 1, us, ue, diff);
}

pll MinMax(ll n, ll qs, ll qe) {
    return MinMaxX(0, n - 1, qs, qe, 0);
}

int main() {
    fast_io;
    ll n;
    cin >> n;
    ll ans = 0;
    ll prev_ans = 0;
    for (int j = 0; j < n; j++) {
        char c;
        cin >> c;
        if (c == 'L') {
            if (i > 0) i--;
            cout << prev_ans << sep;
            continue;
        } else if (c == 'R') {
            i++;
            cout << prev_ans << sep;
            continue;
        } else if (c == '(') {
            update(n, i, n, 1 - a[i]);
            ans += 1 - a[i];
            a[i] = 1;
        } else if (c == ')') {
            update(n, i, n, -1 - a[i]);
            ans += -1 - a[i];
            a[i] = -1;
        } else {
            ans += 0 - a[i];
            update(n, i, n, 0 - a[i]);
            a[i] = 0;
        }

        pll res = {tree[0].min_val, tree[0].max_val};
        if (ans != 0 || res.X < 0) prev_ans = -1;
        else prev_ans = res.Y;
        cout << prev_ans << sep;
    }
    return 0;
}