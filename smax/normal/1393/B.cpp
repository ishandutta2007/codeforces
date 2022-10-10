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

#define MAX 100005

int atLeast2 = 0, atLeast4 = 0, atLeast6 = 0, atLeast8 = 0, cnt[MAX];

void add(int x) {
    cnt[x]++;
    if (cnt[x] == 2)
        atLeast2++;
    else if (cnt[x] == 4)
        atLeast4++;
    else if (cnt[x] == 6)
        atLeast6++;
    else if (cnt[x] == 8)
        atLeast8++;
}

void rem(int x) {
    cnt[x]--;
    if (cnt[x] == 1)
        atLeast2--;
    else if (cnt[x] == 3)
        atLeast4--;
    else if (cnt[x] == 5)
        atLeast6--;
    else if (cnt[x] == 7)
        atLeast8--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        add(a);
    }

    int q;
    cin >> q;
    while (q--) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
            add(x);
        else
            rem(x);
        DEBUG(atLeast2, atLeast4, atLeast8)
        cout << (atLeast4 > 0 && (atLeast8 > 0 || (atLeast6 > 0 && atLeast2 > 1) || atLeast2 > 2 || atLeast4 > 1) ? "YES" : "NO") << "\n";
    }

    return 0;
}