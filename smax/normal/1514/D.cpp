#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int MAX = 3e5 + 5;
const int SZ = 550;

struct Query {
    int l, r, idx;

    bool operator < (const Query &other) const {
        if (l / SZ == other.l / SZ) {
            if (r == other.r)
                return idx < other.idx;
            return l / SZ % 2 ? r > other.r : r < other.r;
        }
        return l < other.l;
    }
};

int cnt[MAX], val[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    vector<Query> queries(q);
    for (int i=0; i<q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].idx = i;
    }

    int ans = 0;
    val[0] = MAX;

    auto add = [&] (int i) -> void {
        val[cnt[a[i]]++]--;
        ans = max(ans, cnt[a[i]]);
        val[cnt[a[i]]]++;
    };

    auto rem = [&] (int i) -> void {
        val[cnt[a[i]]--]--;
        if (val[ans] == 0) ans--;
        val[cnt[a[i]]]++;
    };

    sort(queries.begin(), queries.end());
    vector<int> ret(q);
    int moLeft = 0, moRight = -1;
    for (const Query &query : queries) {
        while (moLeft > query.l)
            add(--moLeft);
        while (moRight < query.r)
            add(++moRight);
        while (moLeft < query.l)
            rem(moLeft++);
        while (moRight > query.r)
            rem(moRight--);
        ret[query.idx] = max(ans - (query.r - query.l + 1 - ans + 1), 0) + 1;
    }

    for (int x : ret)
        cout << x << "\n";

    return 0;
}