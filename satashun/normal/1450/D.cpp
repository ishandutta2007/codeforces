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
#define SZ(x) ((int)(x).size())

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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        V<int> a(n);
        rep(i, n) { cin >> a[i]; }
        V<bool> ans(n + 1, false);

        multiset<int> st;
        rep(i, n) st.insert(a[i]);

        {
            V<int> b = a;
            sort(ALL(b));
            ans[1] = true;
            rep(i, n) if (b[i] != i + 1) { ans[1] = false; }
        }

        int l = 0, r = n - 1;
        int c = 1;

        while (l != r) {
            int len = r - l + 1;
            int mini = *st.begin();
            if (mini == c) {
                ans[len] = true;
            } else {
                break;
            }
            if ((a[l] == mini) ^ (a[r] == mini)) {
                st.erase(st.find(mini));
                if (a[l] == mini) {
                    l++;
                } else {
                    r--;
                }
            } else {
                break;
            }
            c++;
        }
        string s(n, '0');
        rep(i, n) if (ans[i + 1]) s[i] = '1';
        cout << s << '\n';
    }
    return 0;
}