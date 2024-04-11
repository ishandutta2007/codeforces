#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

map<pair<int, ll>, ll> cache;
ll eval(int i, ll x) {
    auto key = make_pair(i, x);
    if (cache.count(key)) return cache[key];
    cout << "? " << i + 1 << " " << x << endl;
    ll res; cin >> res; return cache[key] = res;
}

ll search(int i, ll xL, ll xH, ll v) {
    ll res = xH--;
    while (xL <= xH) {
        ll x = (xL + xH) / 2;
        if (eval(i, x) >= v) res = x, xH = x - 1;
        else xL = x + 1;
    }
    return res;
}

void solve(vector<array<ll, 2>>& ans, vi& elts, ll xL, ll xH, ll vL, ll vH) {
    if (sz(elts) == 1) { ans[elts[0]] = { xL, xH }; return; }
    int targ = (sz(elts) + 1) / 2;
    ll vM = vL + (vH - vL) / sz(elts) * targ;

    vi left, middle = elts, right;
    ll lX = xL, rX = xH;

    while (true) {
        int pivot = middle[rng() % sz(middle)];
        ll x = search(pivot, lX, rX, vM);

        vi before, equal = { pivot }, after;
        for (int i : middle) if (i != pivot) {
            ll v = eval(i, x);
            (v == vM ? equal : v > vM ? before : after).push_back(i);
        }

        if (sz(left) + sz(before) >= targ) {
            middle.clear();
            for (int i : before) middle.push_back(i);
            for (int i : equal) middle.push_back(i);
            for (int i : after) right.push_back(i);
            rX = x;
        } else if (sz(left) + sz(before) + sz(equal) >= targ) {
            for (int i : before) left.push_back(i);
            for (int i : equal) (sz(left) < targ ? left : right).push_back(i);
            for (int i : after) right.push_back(i);

            solve(ans, left, xL, x, vL, vM);
            solve(ans, right, x, xH, vM, vH);
            return;
        } else {
            middle.clear();
            for (int i : before) left.push_back(i);
            for (int i : equal) middle.push_back(i);
            for (int i : after) middle.push_back(i);
            lX = x;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N; ll L;
    cin >> N >> L;

    vi elts(N);
    for (int i = 0; i < N; i++) elts[i] = i;

    vector<array<ll, 2>> ans(N);
    solve(ans, elts, 0, 1e18, 0, L);

    cout << "!\n";
    for (int i = 0; i < N; i++)
        cout << ans[i][0] << " " << ans[i][1] << "\n";
    cout.flush();

    return 0;
}