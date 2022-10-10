#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

#define MAX 100001

bitset<MAX> prime;
vector<int> primeList;

void sieve(int n) {
    prime.set();
    prime[0] = prime[1] = 0;
    primeList.push_back(2);
    for (int i=4; i<=n; i+=2)
        prime[i] = 0;
    for (int p=3; p<=n; p+=2)
        if (prime[p]) {
            primeList.push_back(p);
            if (p < 1000)
                for (int i=p*p; i<=n; i+=2*p)
                    prime[i] = 0;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    sieve(n);

    int a = 1;
    vector<int> pre(n + 1);
    for (int i=2; i<=n; i++) {
        int pm = -1;
        for (int p : primeList) {
            if (i % p == 0) {
                pm = p;
                break;
            }
        }
        if (pm == -1)
            pm = i;
        if (pre[pm] == 0) {
            pre[pm] = a++;
        }
        cout << pre[pm] << " ";
    }
    cout << "\n";

    return 0;
}