#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

// Source: https://codeforces.com/blog/entry/77480

#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    long long x;
    cin >> n >> d >> x;

    auto getNextX = [&] () -> long long {
        return x = (x * 37 + 10007) % 1000000007;
    };

    vector<int> a(n), b(n);
    iota(a.begin(), a.end(), 1);
    for (int i=0; i<n; i++) {
        swap(a[i], a[getNextX() % (i + 1)]);
        b[i] = i < d;
    }
    for (int i=0; i<n; i++)
        swap(b[i], b[getNextX() % (i + 1)]);

    bitset<100000> bt;
    for (int i=0; i<n; i++)
        bt[i] = b[i];

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    sort(perm.begin(), perm.end(), [&] (int i, int j) -> bool {
        return a[i] > a[j];
    });

    vector<int> c(n);
    bitset<100000> zero;
    zero.set();
    for (int i : perm) {
        bitset<100000> cur = zero & (bt << i);
        for (int j=(int)cur._Find_first(); j<n; j=(int)cur._Find_next(j)) {
            c[j] = a[i];
            zero[j] = 0;
        }
    }

    for (int i=0; i<n; i++)
        cout << c[i] << "\n";

    return 0;
}