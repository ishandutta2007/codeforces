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

    vector<long long> a(3), b(3);
    for (int i=0; i<3; i++)
        cin >> a[i];

    iota(b.begin(), b.end(), 0);
    sort(b.begin(), b.end(), [&] (int x, int y) {
        return a[x] < a[y];
    });

    cout << "First\n" << 2 * a[b[2]] - a[b[1]] - a[b[0]] << endl;
    int x;
    cin >> x;
    if (x == 0)
        return 0;

    int which = find(b.begin(), b.end(), x - 1) - b.begin();
    if (which == 0) {
        cout << a[b[2]] - a[b[1]] << endl;
        cin >> x;
        assert(x == 0);
    } else if (which == 1) {
        cout << a[b[2]] - a[b[0]] << endl;
        assert(x == 0);
    } else {
        a[b[2]] += 2 * a[b[2]] - a[b[1]] - a[b[0]];
        cout << 2 * a[b[2]] - a[b[1]] - a[b[0]] << endl;
        cin >> x;
        if (x == 0)
            return 0;

        which = find(b.begin(), b.end(), x - 1) - b.begin();
        cout << a[b[2]] - a[b[1-which]] << endl;
        cin >> x;
        assert(x == 0);
    }

    return 0;
}