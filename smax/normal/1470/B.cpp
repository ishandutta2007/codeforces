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

const int MAX = 1e3 + 1;
const int NP = 168;

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

    sieve();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bitset<NP>> bt(n);
        vector<int> extra(n);
        map<int, unordered_map<bitset<NP>, int>> mp;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            for (int j=0; j<NP; j++) {
                int p = primeList[j];
                if (p > a / p)
                    break;
                while (a % p == 0) {
                    a /= p;
                    bt[i].flip(j);
                }
            }
            if (a > 1) {
                int j = lower_bound(primeList.begin(), primeList.end(), a) - primeList.begin();
                if (j < NP)
                    bt[i].flip(j);
                else
                    extra[i] = a;
            }
            mp[extra[i]][bt[i]]++;
        }
        int q;
        cin >> q;
        vector<int> zero, noZero;
        for (int i=0; i<q; i++) {
            long long w;
            cin >> w;
            if (w == 0)
                zero.push_back(i);
            else
                noZero.push_back(i);
        }

        vector<int> d(n);
        for (int i=0; i<n; i++)
            d[i] = mp[extra[i]][bt[i]];

        int mx = *max_element(d.begin(), d.end());
        vector<int> ret(q);
        for (int j : zero)
            ret[j] = mx;

        for (int i=0; i<n; i++)
            if ((bt[i].count() > 0 || extra[i] > 0) && mp[extra[i]][bt[i]] % 2 == 0) {
                bt[i].reset();
                extra[i] = 0;
                mp[extra[i]][bt[i]]++;
            }
        for (int i=0; i<n; i++)
            d[i] = mp[extra[i]][bt[i]];
        mx = *max_element(d.begin(), d.end());
        for (int j : noZero)
            ret[j] = mx;

        for (int j=0; j<q; j++)
            cout << ret[j] << "\n";
    }

    return 0;
}