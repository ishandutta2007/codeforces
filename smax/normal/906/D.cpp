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

const int MAX = 31623;

bitset<MAX> prime;
vector<int> primeList;

void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    primeList.push_back(2);
    for (int i=4; i<MAX; i+=2)
        prime[i] = 0;
    for (int p=3; p<MAX; p+=2)
        if (prime[p]) {
            primeList.push_back(p);
            for (int i=p; i<=(MAX-1)/p; i+=2)
                prime[i*p] = 0;
        }
}

int phi(int n) {
    int ret = n;
    for (int p : primeList) {
        if (p > n / p)
            break;
        if (n % p == 0) {
            ret -= ret / p;
            while (n % p == 0)
                n /= p;
        }
    }
    if (n > 1)
        ret -= ret / n;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (int i=0; i<n; i++)
        cin >> w[i];

    vector<int> mod{m};
    while (mod.back() > 1)
        mod.push_back(phi(mod.back()));

    auto reduce = [] (long long a, int b) -> long long {
        return a < b ? a : a % b + b;
    };

    auto recur = [&] (auto &self, int l, int r, int i) -> long long {
        if (mod[i] == 1)
            return 1;
        if (l == r)
            return reduce(w[l], mod[i]);
        long long ret = 1, a = w[l];
        for (long long b=self(self, l+1, r, i+1); b>0; b/=2) {
            if (b % 2) ret = reduce(ret * a, mod[i]);
            a = reduce(a * a, mod[i]);
        }
        return ret;
    };

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << recur(recur, l, r, 0) % m << "\n";
    }

    return 0;
}