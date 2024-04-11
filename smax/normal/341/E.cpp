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

    int n;
    cin >> n;
    vector<int> a(n), boxes;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] > 0)
            boxes.push_back(i);
    }

    if (boxes.size() <= 1) {
        cout << "-1\n";
        return 0;
    }

    vector<pair<int, int>> ret;

    auto sort3 = [&] (int &i, int &j, int &k) -> void {
        if (a[i] > a[j]) swap(i, j);
        if (a[j] > a[k]) swap(j, k);
        if (a[i] > a[j]) swap(i, j);
    };

    auto op = [&] (int i, int j) -> void {
        ret.emplace_back(i, j);
        a[j] -= a[i];
        a[i] *= 2;
    };

    while (boxes.size() > 2) {
        int i = boxes.back();
        boxes.pop_back();
        int j = boxes.back();
        boxes.pop_back();
        int k = boxes.back();
        boxes.pop_back();
        sort3(i, j, k);
        while (a[i] > 0) {
            int x = a[j] / a[i];
            for (int b=0; 1<<b<=x; b++) {
                if (x >> b & 1)
                    op(i, j);
                else
                    op(i, k);
            }
            sort3(i, j, k);
        }
        if (a[i] > 0) boxes.push_back(i);
        if (a[j] > 0) boxes.push_back(j);
        if (a[k] > 0) boxes.push_back(k);
    }

    cout << ret.size() << "\n";
    for (auto [i, j] : ret)
        cout << i + 1 << " " << j + 1 << "\n";

    return 0;
}