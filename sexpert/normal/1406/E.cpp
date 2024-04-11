#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int SQ = 320;
const int TRES = 100;

int queries = 0;

int ask(int t, int a) {
    queries++;
    if(t == 1)
        cout << "A " << a << '\n' << flush;
    if(t == 2)
        cout << "B " << a << '\n' << flush;
    int res;
    cin >> res;
    return res;
}

const int MAXN = 1e5 + 10;
int n;
vector<ll> primes;
int sv[MAXN];

void sieve() {
    for(int p = 2; p <= n; p++) {
        if(sv[p])
            continue;
        primes.push_back(p);
        for(int q = p; q <= n; q += p)
            sv[q] = p;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    if(n <= 4000) {
        for(int i = n; i >= 2; i--) {
            ask(2, i);
            if(ask(1, i) != 0) {
                cout << "C " << i << '\n' << flush;
                return 0;
            }
        }
        cout << "C 1" << '\n' << flush;
        return 0;
    }

    sieve();

    ll x = 1;
    /*for(auto p : primes) {
        if(p > SQ)
            break;
        ask(2, p);
        ll pot = 1;
        while(p * pot * x <= n && ask(1, p * pot))
            pot *= p;
        x *= pot;
    }
    cerr << x << '\n';*/
    vector<ll> bigp;
    for(auto p : primes) {
        if(p > SQ)
            bigp.push_back(p);
    }

    ll rem = n;
    bool hasbig = false;

    for(int i = 0; i < bigp.size(); i++) {
        rem -= n / bigp[i];
        ask(2, bigp[i]);
        if(i % TRES == TRES - 1 && !hasbig) {
            if(ask(1, 1) != rem) {
                for(int j = i - TRES + 1; j <= i; j++) {
                    if(ask(1, bigp[j])) {
                        x *= bigp[j];
                        hasbig = true;
                        break;
                    }
                }
            }
        }
    }

    int sz = bigp.size();
    if(!hasbig && ask(1, 1) != rem) {
        for(int j = TRES * (sz / TRES); j < sz; j++) {
            if(ask(1, bigp[j])) {
                x *= bigp[j];
                hasbig = true;
                break;
            }
        }
    }

    for(auto p : primes) {
        if(p > SQ)
            break;
        ask(2, p);
        ll pot = 1;
        while(p * pot * x <= n && ask(1, p * pot))
            pot *= p;
        x *= pot;
    }

    assert(queries <= 9999);

    cout << "C " << x << flush;
}