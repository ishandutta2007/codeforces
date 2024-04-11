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

int n, m, p[200000];
long long t;

bool f(int d) {
    int cnt = 0;
    long long ti = 0, cur = 0;
    for (int i=0; i<n; i++) {
        if (p[i] > d)
            continue;
        if (ti + p[i] > t)
            return false;
        ti += p[i];
        cur += p[i];
        if (++cnt == m) {
            ti += cur;
            cnt = cur = 0;
        }
    }
    return true;
}

int eval(int d) {
    int cnt = 0, ret = 0;
    long long ti = 0, cur = 0;
    for (int i=0; i<n; i++) {
        if (p[i] > d)
            continue;
        if (ti + p[i] > t)
            break;
        ti += p[i];
        cur += p[i];
        ret++;
        if (++cnt == m) {
            ti += cur;
            cnt = cur = 0;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int c;
    cin >> c;
    while (c--) {
        cin >> n >> m >> t;
        for (int i=0; i<n; i++)
            cin >> p[i];

        int l = 1, r = min(200000LL, t);
        while (l < r) {
            int mid = (l + r) / 2;
            if (f(mid))
                l = mid + 1;
            else
                r = mid;
        }

        pair<int, int> ret = max(make_pair(eval(l-1), l-1), make_pair(eval(l), l));
        cout << ret.first << " " << ret.second << "\n";
    }

    return 0;
}