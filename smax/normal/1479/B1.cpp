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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    int ret = 0, pred0 = -1, v0 = -1, pred1 = -1, v1 = -1;
    for (int i=0; i<n; ) {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        DEBUG(i, j);
        ret += min(j - i, 2);
        bool f = false;
        if (j - i >= 2 && pred1 == 1 && pred0 >= 2 && a[i] == v0)
            ret--;
        else if (j - i == 1 && pred1 == 1 && pred0 >= 2 && a[i] == v0)
            f = true;
        pred0 = pred1;
        v0 = v1;
        pred1 = f ? 2 : j - i;
        v1 = a[i];
        i = j;
    }
    cout << ret << "\n";

    return 0;
}