#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define MAX 200000

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
            if (p < 500)
                for (int i=p*p; i<MAX; i+=2*p)
                    prime[i] = 0;
        }
}

int power(int a, int b) {
    int ret = 1;
    for (; b>0; b/=2) {
        if (b % 2) ret *= a;
        a *= a;
    }
    return ret;
}

int mn1[MAX], mn2[MAX], has[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    sieve();
    memset(mn1, 127, sizeof(mn1));
    memset(mn2, 127, sizeof(mn2));

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;

        for (int p : primeList) {
            if (1LL * p * p > a)
                break;
            if (a % p == 0) {
                has[p]++;
                int cnt = 0;
                while (a % p == 0) {
                    a /= p;
                    cnt++;
                }
                if (cnt < mn1[p]) {
                    mn2[p] = mn1[p];
                    mn1[p] = cnt;
                } else if (cnt < mn2[p]) {
                    mn2[p] = cnt;
                }
            }
        }
        if (a > 1) {
            has[a]++;
            if (mn1[a] > 1) {
                mn2[a] = mn1[a];
                mn1[a] = 1;
            } else if (mn2[a] > 1) {
                mn2[a] = 1;
            }
        }
    }

    long long ret = 1;
    for (int p : primeList) {
        if (has[p] == n)
            ret *= power(p, mn2[p]);
        else if (has[p] == n - 1)
            ret *= power(p, mn1[p]);
    }

    cout << ret << "\n";

    return 0;
}