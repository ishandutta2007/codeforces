#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

template<typename T>
struct SegmentTree {
    int n;
    vector<T> st;

    SegmentTree(int _n) : n(_n), st(2 * n, -1) {}

    SegmentTree(const vector<T> &a) {
        n = a.size();
        for (int i=0; i<n; i++)
            st[i+n] = a[i];
        for (int i=n-1; i>0; i--)
            st[i] = max(st[i<<1], st[i<<1|1]);
    }

    T query(int l, int r) {
        T ret = -1;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) ret = max(ret, st[l++]);
            if (r&1) ret = max(ret, st[--r]);
        }
        return ret;
    }

    void update(int p, T val) {
        p += n;
        for (st[p]=max(st[p], val); p>1; p>>=1)
            st[p>>1] = max(st[p], st[p^1]);
    }
};

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> pref(n);
    for (int i=0; i<n; i++)
        pref[i] = (i > 0 ? pref[i-1] : 0) + (isVowel(s[i]) ? -1 : 2);

    SegmentTree<int> st(3 * n + 1);
    int mx = 0, cnt = 0;
    for (int i=n-1; i>=0; i--) {
        st.update(pref[i] + n, i);
        int j = st.query((i > 0 ? pref[i-1] : 0) + n, 3 * n + 1);
        if (j >= i) {
            if (j - i + 1 > mx) {
                mx = j - i + 1;
                cnt = 0;
            }
            if (j - i + 1 == mx)
                cnt++;
        }
    }
    if (mx == 0)
        cout << "No solution\n";
    else
        cout << mx << " " << cnt << "\n";

    return 0;
}