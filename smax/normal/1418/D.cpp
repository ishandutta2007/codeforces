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

int p[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++)
        cin >> p[i];

    sort(p, p + n);
    set<int> st(p, p + n);
    multiset<int> gaps;
    for (int i=1; i<n; i++)
        gaps.insert(p[i] - p[i-1]);
    cout << (st.empty() ? 0 : *st.rbegin() - *st.begin()) - (gaps.empty() ? 0 : *gaps.rbegin()) << "\n";

    for (int i=0; i<q; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            auto it = st.find(x);
            if (it != st.begin())
                gaps.erase(gaps.find(x - *(--it)));
            it = st.erase(st.find(x));
            if (it != st.end()) {
                int y = *it;
                gaps.erase(gaps.find(y - x));
                if (it != st.begin())
                    gaps.insert(y - *(--it));
            }
        } else {
            auto it = st.lower_bound(x);
            if (it != st.begin() && it != st.end()) {
                int y = *it;
                gaps.erase(gaps.find(y - *(--it)));
            }
            it = st.insert(x).first;
            if (it != st.begin())
                gaps.insert(x - *prev(it));
            if (next(it) != st.end())
                gaps.insert(*next(it) - x);
        }
        cout << (st.empty() ? 0 : *st.rbegin() - *st.begin()) - (gaps.empty() ? 0 : *gaps.rbegin()) << "\n";
    }

    return 0;
}