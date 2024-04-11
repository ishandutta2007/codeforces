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

bool solve(const vector<int> &a, int m, int l, int r) {
    int n = a.size();
    bool ret = false;
    for (int i=0, j=n, k=n; i<n; i++) {
        j = max(j, i + 1);
        k = max(k, j);
        while (j - 1 > i && a[i] % m + a[j-1] % m >= l)
            j--;
        while (k - 1 >= j && a[i] % m + a[k-1] % m > r)
            k--;
        ret ^= (k - j) % 2;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    int power = 1, ret = 0;
    for (int j=0; j<25; j++) {
        stable_partition(a.begin(), a.end(), [&] (int x) {return !(x & power);});
        power *= 2;
        if (solve(a, power, 1 << j, (1 << (j + 1)) - 1) ^ solve(a, power, (1 << j) + (1 << (j + 1)), (1 << (j + 2)) - 1))
            ret |= 1 << j;
    }
    cout << ret << "\n";

    return 0;
}