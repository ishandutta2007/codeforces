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

const int LOG = 40;

long long basis[LOG], actual[LOG], ops[LOG];

void add(long long x) {
    long long y = x, mask = 0;
    for (int i=0; i<LOG; i++)
        if (x & (1LL << i)) {
            if (!basis[i]) {
                basis[i] = x;
                actual[i] = y;
                ops[i] = mask ^ (1LL << i);
                return;
            }
            x ^= basis[i];
            mask ^= ops[i];
        }
}

bool query(long long x) {
    for (int i=0; i<LOG; i++)
        if (x & (1LL << i))
            x ^= basis[i];
    return x == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;
    add(x);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    auto distr = uniform_int_distribution<long long>(0, 1LL << LOG);
    vector<tuple<long long, char, long long>> ret;

    auto build = [&] (long long take) -> void {
        long long mask = 0;
        for (int i=0; i<LOG; i++)
            if (take & (1LL << i))
                mask ^= ops[i];
        vector<long long> v;
        for (int i=0; i<LOG; i++)
            if (mask & (1LL << i))
                v.push_back(actual[i]);
        for (int i=1; i<(int)v.size(); i++) {
            ret.emplace_back(v[i-1], '^', v[i]);
            v[i] ^= v[i-1];
        }
    };

    while (!query(1)) {
        long long takeA = distr(rng), takeB = distr(rng), a = 0, b = 0;
        for (int i=0; i<LOG; i++) {
            if (takeA & (1LL << i))
                a ^= basis[i];
            if (takeB & (1LL << i))
                b ^= basis[i];
        }
        if (a + b < 1LL << LOG && !query(a + b)) {
            build(takeA);
            build(takeB);
            ret.emplace_back(a, '+', b);
            add(a + b);
        }
    }

    long long take = 0, val = 1;
    for (int i=0; i<LOG; i++)
        if (val & (1LL << i)) {
            take ^= 1LL << i;
            val ^= basis[i];
        }
    build(take);

    cout << ret.size() << "\n";
    for (auto [a, op, b] : ret)
        cout << a << " " << op << " " << b << "\n";

    return 0;
}