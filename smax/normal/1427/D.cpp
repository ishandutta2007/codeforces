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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    vector<int> b(n);
    vector<vector<int>> ret;
    bool done = false;
    while (!done) {
        done = true;
        for (int x=1; x<n; x++) {
            int i = find(a.begin(), a.end(), x + 1) - a.begin(), j = find(a.begin(), a.end(), x) - a.begin();
            if (i < j) {
                done = false;
                int k = i;
                while (k < j && a[k] < a[k+1])
                    k++;
                assert(k < j);
                ret.push_back({i, k - i + 1, j - k, n - j - 1});
                auto it = ret.back().begin();
                while (it != ret.back().end()) {
                    if (*it == 0)
                        it = ret.back().erase(it);
                    else
                        it++;
                }
                int idxA = n, idxB = 0;
                for (int l=(int)ret.back().size()-1; l>=0; l--) {
                    idxA -= ret.back()[l];
                    for (int m=0; m<ret.back()[l]; m++)
                        b[idxB++] = a[idxA + m];
                }
                a = b;
            }
        }
    }

    assert((int) ret.size() <= n);
    cout << ret.size() << "\n";
    for (auto &v : ret) {
        cout << v.size();
        for (int x : v)
            cout << " " << x;
        cout << "\n";
    }

    return 0;
}