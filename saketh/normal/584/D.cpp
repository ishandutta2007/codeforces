#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXV = 10000;

bool is_prime(int v) {
    for (ll p = 2; p * p <= v; p++)
        if (v % p == 0) return false;
    return true;
}

int sieve[MAXV];
vector<int> primes;

bool create[2 * MAXV];
int a[2 * MAXV];
int b[2 * MAXV];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    for (int p = 2; p < MAXV; p++)
        if (sieve[p]) continue;
        else for (int q = p; q < MAXV; q+=p) 
            sieve[q] = p;

    for (int i = 1; i < MAXV; i++)
        if(sieve[i] == i)
            primes.push_back(i);

    for (int i = 0; i < primes.size(); i++)
        for (int j = i; j < primes.size(); j++) {
            int sum = primes[i] + primes[j];

            if (!create[sum]) {
                create[sum] = true;
                a[sum] = primes[i];
                b[sum] = primes[j];
            }
        }

    for(int v = 4; v < MAXV; v += 2)
        assert(create[v]);

    int N;
    cin >> N;

    // can we do it with just one?
    if (is_prime(N)) {
        cout << 1 << "\n" << N << "\n";
        return 0;
    }

    // how about two?
    if (is_prime(N - 2)) {
        cout << 2 << "\n" << 2 << " " << N-2 << "\n";
        return 0;
    }

    // thx goldbach
    for (int gap = 4; ; gap += 2) {
        if (is_prime(N - gap)) {
            cout << 3 << "\n";
            cout << a[gap] << " " << b[gap] << " " << N - gap << "\n";
            return 0;
        }
    }
}