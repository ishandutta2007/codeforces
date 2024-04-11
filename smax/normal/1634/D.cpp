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

int query(int i, int j, int k) {
    cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    int ret;
    cin >> ret;
    assert(ret != -1);
    return ret;
}

void answer(int i, int j) {
    cout << "! " << i + 1 << " " << j + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int mx = -1, cand = -1;
        for (int i=2; i<n; i++) {
            int cur = query(0, 1, i);
            if (cur > mx) {
                mx = cur;
                cand = i;
            }
        }

        int mx2 = -1, cand2 = -1;
        for (int i=1; i<n; i++)
            if (i != cand) {
                int cur = query(0, i, cand);
                if (cur > mx2) {
                    mx2 = cur;
                    cand2 = i;
                }
            }

        int diff = 1;
        while (diff == cand || diff == cand2)
            diff++;

        if (query(diff, cand, cand2) != mx2) {
            if (query(0, diff, cand2) != mx2)
                answer(0, cand);
            else
                answer(0, cand2);
        } else {
            answer(cand, cand2);
        }
    }

    return 0;
}