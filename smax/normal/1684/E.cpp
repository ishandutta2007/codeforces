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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            mp[a]++;
        }

        int sum = 0, usedSum = 0;
        multiset<int> st, used;
        for (const auto &p : mp) {
            st.insert(p.second);
            sum += p.second;
        }
        for (auto it=st.begin(); it!=st.end(); ) {
            if (*it <= k) {
                k -= *it;
                sum -= *it;
                usedSum += *it;
                used.insert(*it);
                it = st.erase(it);
            } else {
                it++;
            }
        }

        int ret = INT_MAX, need = 0;
        for (int mex=0; mex<=n; mex++) {
            if (need > usedSum) {
                if (need - usedSum <= k && need - usedSum <= sum)
                    ret = min(ret, (int) st.size());
            } else {
                ret = min(ret, (int) st.size());
            }
            if (mp.contains(mex)) {
                auto it = st.find(mp[mex]);
                if (it == st.end()) {
                    it = used.find(mp[mex]);
                    assert(it != used.end());
                    k += *it;
                    sum += *it;
                    usedSum -= *it;
                    used.erase(it);
                } else {
                    st.erase(it);
                }
                sum--;
                while (!st.empty() && *st.begin() <= k) {
                    k -= *st.begin();
                    sum -= *st.begin();
                    usedSum += *st.begin();
                    used.insert(*st.begin());
                    st.erase(st.begin());
                }
            } else {
                need++;
            }
        }
        cout << ret << "\n";
    }

    return 0;
}