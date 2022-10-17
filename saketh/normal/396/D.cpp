#include<iostream>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;
const int MOD = 1000000007;
const ll HALF = 500000004;

int bit[MAXN];
int read(int k){
    int sum = 0;
    while(k > 0){ sum += bit[k]; k -= (k & -k); }
    return sum;
}
void update(int i, int v){
    while(i < MAXN){ bit[i]+=v; i += (i & -i); }
}

int N, v[MAXN];
ll fact[MAXN], nch2[MAXN], tinv[MAXN];
ll car = 0, ans = 0;

int main(){
    fact[0] = 1;
    for(int i=1; i<MAXN; i++){
        fact[i] = (i * fact[i-1]) % MOD;
        nch2[i] = ((i * (i-1LL)) % MOD * HALF) % MOD;
        tinv[i] = ((nch2[i] * HALF) % MOD * fact[i]) % MOD;
    }

    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> v[i];
        ll sma = v[i] - 1 - read(v[i]);
        ll k = N - i - 1;

        ll res = (tinv[k] * sma) % MOD;
        ll ext = (fact[k] * nch2[sma]) % MOD;
        ll old = ((fact[k] * sma) % MOD * car) % MOD;
        ll tot = (res + ext + old) % MOD;

        ans = (ans + tot) % MOD;

        car = (car + sma) % MOD;
        update(v[i]+1, 1);
    }

    cout << (ans + car) % MOD << endl;
    return 0;
}