#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const ll MOD = 1e9 + 9;

ll N, M, K;

ll mod_pow(ll b, ll e){
    if(e == 0) return 1;
    if(e&1) return b * mod_pow(b, e-1) % MOD;
    return mod_pow(b * b % MOD, e/2);
}

int main(){
    setup();
    cin >> N >> M >> K;

    ll W = N - M;
    ll F = N - W * K;

    ll D = (F < K) ? 0 : (F / K);
    ll R = M - D * K;

    ll A = (mod_pow(2, D) - 1 + MOD) % MOD; 
    A = (A * 2 * K) % MOD;
    A = (A + R) % MOD;

    cout << A << endl;
}