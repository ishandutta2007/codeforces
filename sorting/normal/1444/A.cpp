#include <bits/stdc++.h>

using namespace std;

long long get_d(long long p, long long prime){
    long long d = 1;
    while(p % prime == 0){
        p /= prime;
        d *= prime;
    }
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        long long p, q;
        cin >> p >> q;

        if(p % q){
            cout << p << "\n";
            continue;
        }

        vector<array<long long, 2>> primes;
        for(long long i = 2; i * i <= q; ++i){
            if(q % i == 0){
                long long d = 1;
                while(q % i == 0){
                    q /= i;
                    d *= i;
                }
                primes.push_back({i, d});
            }
        }
        if(q != 1) primes.push_back({q, q});

        long long ans = p;
        for(auto [prime, d]: primes){
            long long d2 = get_d(p, prime);
            ans = min(ans, d2 / d * prime);
        }

        ans = p / ans;
        cout << ans << "\n";
    }
}