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

int n, pos[100005], bit[100005];

int query(int i) {
    int ret = 0;
    for (; i>0; i-=i&-i)
        ret += bit[i];
    return ret;
}

void update(int i) {
    for (; i<=n; i+=i&-i)
        bit[i]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        pos[a] = i;
    }

    int ret = 0;
    for (int i=1; i<=n; i++) {
        int b;
        cin >> b;
        ret += (query(pos[b] - 1) < pos[b] - 1);
        update(pos[b]);
    }
    cout << ret << "\n";

    return 0;
}