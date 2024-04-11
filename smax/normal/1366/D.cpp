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

#define MAX 10000000

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    sieve();

    int n;
    cin >> n;
    vector<pair<int, int>> ret;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        int d1 = -1, d2 = 1;
        for (int p : primeList) {
            if (p > a / p)
                break;
            if (a % p == 0) {
                if (d1 == -1) d1 = p;
                else d2 *= p;
                while (a % p == 0) a /= p;
            }
        }
        if (a > 1) {
            if (d1 == -1) d1 = a;
            else d2 *= a;
        }
        if (d1 == -1 || d2 == 1) ret.emplace_back(-1, -1);
        else ret.emplace_back(d1, d2);
    }

    for (int i=0; i<n; i++)
        cout << ret[i].first << " \n"[i==n-1];
    for (int i=0; i<n; i++)
        cout << ret[i].second << " \n"[i==n-1];

    return 0;
}