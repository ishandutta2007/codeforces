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

bitset<100005> prime;
vector<int> primeList;

void sieve(int n) {
    prime.set();
    prime[0] = prime[1] = 0;
    if (n >= 2) {
        primeList.push_back(2);
        for (int i=4; i<=n; i+=2)
            prime[i] = 0;
    }
    for (int p=3; p<=n; p+=2)
        if (prime[p]) {
            primeList.push_back(p);
            for (int i=p; i<=n/p; i+=2)
                prime[i*p] = 0;
        }
}

int ask(char c, int a) {
    cout << c << " " << a << endl;
    int ret;
    cin >> ret;
    return ret;
}

bool out[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    sieve(n);
    int tot = n, rt = sqrt(primeList.size()), last = 0, ret = 1;
    for (int i=0; i<(int)primeList.size(); i++) {
        int expected = 0, actual = ask('B', primeList[i]);
        for (int j=primeList[i]; j<=n; j+=primeList[i])
            if (!out[j]) {
                out[j] = true;
                expected++;
            }
        if (expected != actual) {
            tot++;
            int val = 1;
            while (val <= n / primeList[i] && ask('A', val * primeList[i]))
                val *= primeList[i];
            ret *= val;
        }
        tot -= actual;
        if (i > 0 && i % rt == 0) {
            if (ask('A', 1) != tot) {
                tot++;
                for (int j=last; j<=i; j++) {
                    int val = 1;
                    while (val <= n / primeList[j] && ask('A', val * primeList[j]))
                        val *= primeList[j];
                    ret *= val;
                    if (val > 1)
                        break;
                }
            }
            last = i + 1;
        }
    }
    if (last < (int) primeList.size() && ask('A', 1) != tot) {
        for (int j=last; j<(int)primeList.size(); j++) {
            int val = primeList[j];
            while (val <= n && ask('A', val))
                val *= primeList[j];
            ret *= val / primeList[j];
        }
    }
    cout << "C " << ret << endl;

    return 0;
}