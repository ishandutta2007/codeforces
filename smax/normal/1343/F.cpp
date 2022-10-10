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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<set<int>> seg(n-1);
        for (int i=0; i<n-1; i++) {
            int k;
            cin >> k;
            while (k--) {
                int a;
                cin >> a;
                seg[i].insert(a);
            }
        }

        for (int x=1; x<=n; x++) {
            vector<set<int>> cur = seg;
            vector<int> p(n);
            p[0] = x;
            bool ok = true;
            for (int i=1; i<n; i++) {
                for (auto &st : cur)
                    st.erase(p[i-1]);
                sort(cur.begin(), cur.end(), [] (const set<int> &a, const set<int> &b) {
                    return a.size() > b.size();
                });
                if (cur.back().size() != 1 || (cur.size() > 1 && cur[cur.size()-2].size() == 1)) {
                    ok = false;
                    break;
                }
                p[i] = *cur.back().begin();
                cur.pop_back();
            }
            if (ok) {
                set<set<int>> verify;
                for (auto &st : seg)
                    verify.insert(st);
                bool ok2 = true;
                for (int i=1; i<n; i++) {
                    ok2 = false;
                    set<int> st;
                    for (int j=i; j>=0; j--) {
                        st.insert(p[j]);
                        if (verify.count(st)) {
                            verify.erase(st);
                            ok2 = true;
                            break;
                        }
                    }
                    if (!ok2)
                        break;
                }
                if (ok2) {
                    for (int i=0; i<n; i++)
                        cout << p[i] << " ";
                    cout << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}