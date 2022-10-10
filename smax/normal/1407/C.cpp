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

    int n;
    cin >> n;

    vector<int> p(n), v(n);
    vector<bool> has(n + 1);
    iota(v.begin(), v.end(), 1);
    while (v.size() >= 2) {
        int a = v.back();
        v.pop_back();
        int b = v.back();
        v.pop_back();
        cout << "? " << a << " " << b << endl;
        int ab;
        cin >> ab;
        cout << "? " << b << " " << a << endl;
        int ba;
        cin >> ba;

        if (ab > ba) {
            p[a-1] = ab;
            has[ab] = true;
            v.push_back(b);
        } else {
            assert(ab < ba);
            p[b-1] = ba;
            has[ba] = true;
            v.push_back(a);
        }
    }
    p[v[0]-1] = 1;
    while (has[p[v[0]-1]])
        p[v[0]-1]++;

    cout << "!";
    for (int x : p)
        cout << " " << x;
    cout << endl;

    return 0;
}