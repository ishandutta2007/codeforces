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
        int n;
        cin >> n;
        vector<int> deg(n);
        for (int i=1; i<n; i++) {
            int p;
            cin >> p;
            deg[--p]++;
        }

        deg.push_back(1);
        erase_if(deg, [] (int x) -> bool {
            return x == 0;
        });
        sort(deg.rbegin(), deg.rend());

        int delta = 0, ret = 0;
        priority_queue<int> pq;
        for (int x : deg) {
            pq.push(x - delta);
            delta--;
            ret++;
        }
        while (!pq.empty()) {
            int x = pq.top() + delta;
            pq.pop();
            if (x > 0) {
                pq.push(x - delta - 1);
                delta--;
                ret++;
            }
        }
        cout << ret << "\n";
    }

    return 0;
}