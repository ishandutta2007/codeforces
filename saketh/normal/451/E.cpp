#include <iostream>
#include <map>
#define MOD 1000000007
using namespace std;

long long N, S, f[32];

long long mod_pow(long long b, long long e){
    if(!e) return 1LL;
    if(e%2) return (b * mod_pow((b*b)%MOD, e/2)) % MOD;
    return mod_pow((b*b)%MOD, e/2);
}

map<long long, long long> cache;
long long inv(long long v){
    if(cache.count(v)) return cache[v];
    return cache[v] = mod_pow(v, MOD-2);
}

long long ncr(long long N, long long K){
    long long res = 1;
    for(long long top = N; top > N-K; top--)
        res = (res * (top%MOD)) % MOD;

    for(long long bot = 1; bot <= K; bot++)
        res = (res * inv(bot)) % MOD;

    return res;
}

int main(){
    cin >> N >> S;
    for(int i=0; i<N; i++)
        cin >> f[i];
    
    long long ans = 0;

    for(int m = 0; m < (1<<N); m++){
        long long left = S;
        for(int i=0; i<N; i++)
            if((m>>i)&1)
                left -= f[i] + 1;

        if(left < 0) continue;
        long long ways = ncr(left + N - 1, N - 1);
        ans = (ans + ways * ((__builtin_popcount(m)%2)?-1:1)) % MOD;
    }

    cout << (ans + MOD) % MOD << endl;
    return 0;
}