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

const int MAX = 31622;

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

map<int, set<int>> mp;

void primeFactor(int n) {
    int gr = n;
    if (!mp.count(n)) {
        mp[gr];
        for (int p : primeList) {
            if (p > n / p)
                break;
            if (n % p == 0) {
                mp[gr].insert(p);
                while (n % p == 0)
                    n /= p;
            }
        }
        if (n > 1)
            mp[gr].insert(n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    cin >> t;
    set<int> st, primes;
//    map<int, set<int>> bucket;
    while (t--) {
        int n;
        cin >> n;
        st.clear();
        primes.clear();
        DEBUG("THEY")
//        bucket.clear();
        for (int i=1; i*i<=n; i++)
            if (n % i == 0)
                for (int j : {i, n / i}) {
                    if (j == 1)
                        continue;
//                    st.insert(j);
                    primeFactor(j);
                    if (mp[j].size() == 1 && j == *mp[j].begin())
                        primes.insert(j);
                    else {
                        primeFactor(j);
                        st.insert(j);
//                        for (int x : mp[j])
//                            bucket[x].insert(j);
                    }
                }
        vector<int> ret;
        if (primes.size() == 1) {
            // works anyways
            ret.push_back(*primes.begin());
            for (int x : st)
                ret.push_back(x);
        } else if (primes.size() == 2) {
            // two
            int p1 = *primes.begin(), p2 = *primes.rbegin();
            vector<int> top, bottom, huht, huhb;
            for (int x : st) {
                if (x == p1 || x == p2)
                    continue;
                if (mp[x].count(p1)) {
                    if (mp[x].count(p2)) {
                        if (top.empty())
                            top.push_back(x);
                        else
                            bottom.push_back(x);
                    } else {
                        huht.push_back(x);
                    }
                } else {
                    huhb.push_back(x);
                }
            }
            ret.push_back(p1);
            ret.insert(ret.end(), huht.begin(), huht.end());
            ret.insert(ret.end(), top.begin(), top.end());
            ret.push_back(p2);
            ret.insert(ret.end(), huhb.begin(), huhb.end());
            ret.insert(ret.end(), bottom.begin(), bottom.end());
        } else {
            // general
            // 0 - huh, 1 - all
            vector<vector<vector<int>>> buckets(primes.size(), vector<vector<int>>(2));
            DEBUG("HERE")
            map<int, int> cc;
            int idx = 0;
            for (int p : primes) {
                cc[p] = idx++;
            }
            assert(idx == (int) buckets.size());
            for (int x : st) {
//                if (prime[x])
//                    continue;
                if (mp[x].size() == 1) {
                    int p = *mp[x].begin();
                    buckets[cc[p]][0].push_back(x);
                } else {
                    assert(mp[x].size() > 1);
                    int p1 = *mp[x].begin(), p2 = *(++mp[x].begin());
                    if (cc[p1] == 0 && cc[p2] == idx - 1)
                        buckets[cc[p2]][1].push_back(x);
                    else if (abs(cc[p1] - cc[p2]) == 1) {
                        // buddies!
                        buckets[cc[p1]][1].push_back(x);
                    } else {
                        buckets[cc[p1]][0].push_back(x);
                    }
                }
            }
            for (int p : primes) {
                ret.push_back(p);
                for (int j=0; j<2; j++)
                    ret.insert(ret.end(), buckets[cc[p]][j].begin(), buckets[cc[p]][j].end());
            }
        }

        int ans = (ret.size() > 2 && __gcd(ret[0], ret.back()) == 1);
        for (int i=0; i<(int)ret.size()-1; i++)
            ans += (__gcd(ret[i], ret[i+1]) == 1);
//        cout << ans << "\n";
        for (int x : ret)
            cout << x << " ";
        cout << "\n";
        cout << ans << "\n";
    }

    return 0;
}