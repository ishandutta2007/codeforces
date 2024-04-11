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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct Bucket {
    multiset<int> st;
    long long tot = 0;

    void add(int x) {
        st.insert(x);
        tot += x;
    }

    void rem(int x) {
        st.erase(st.find(x));
        tot -= x;
    }

    int size() {
        return (int) st.size();
    }

    int min() {
        return *st.begin();
    }

    int max() {
        return *st.rbegin();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i=0; i<n; i++) {
            cin >> p[i];
            p[i] /= 100;
        }
        int x, a, y, b;
        long long k;
        cin >> x >> a >> y >> b >> k;

        vector<int> bonus(n);
        for (int i=0; i<n; i++) {
            if ((i + 1) % a == 0)
                bonus[i] += x;
            if ((i + 1) % b == 0)
                bonus[i] += y;
        }

        vector<int> costs{0, min(x, y), max(x, y), x + y}, cnt(4);
        vector<Bucket> st(4);
        sort(p.rbegin(), p.rend());
        for (int i=0; i<n; i++) {
            if (bonus[i] == 0)
                cnt[0]++;
            else if (bonus[i] == min(x, y))
                cnt[1]++;
            else if (bonus[i] == max(x, y))
                cnt[2]++;
            else
                cnt[3]++;
            st[0].add(p[i]);
            for (int j=0; j<3; j++)
                while (st[j].size() > cnt[j]) {
                    st[j+1].add(st[j].max());
                    st[j].rem(st[j].max());
                }
            DEBUG(i, st[1].tot, st[2].tot, st[3].tot, cnt, st[1].tot * min(x, y) + st[2].tot * max(x, y) + st[3].tot * (x + y));
            if (st[1].tot * min(x, y) + st[2].tot * max(x, y) + st[3].tot * (x + y) >= k) {
                cout << i + 1 << "\n";
                goto done;
            }
        }
        cout << "-1\n";
        done:;
    }

    return 0;
}