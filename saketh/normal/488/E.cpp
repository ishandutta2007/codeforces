#include <iostream>
using namespace std;

typedef long long ll;

bool prime(ll n){
    if(n == 1) return false;
    for(ll j=2; j*j<=n; j++)
        if(n%j == 0) return false;
    return true;
}

ll mod_pow(ll b, ll e, ll m){
    if(e == 0) return 1LL;
    long long res = mod_pow((b*b)%m, e/2, m);
    return (res * ((e%2)?b:1)) % m;
}

ll N;

int main(){
    cin >> N;
    if(N > 4 && !prime(N)){ cout << "NO" << endl; return 0; }
    cout << "YES\n";

    if(N == 4){ cout << "1\n3\n2\n4" << endl; return 0; }
    else{
        ll v = 1; cout << v << "\n";
        for(ll i=2; i<=N; i++){
            ll res = (i * mod_pow(v, N-2, N)) % N;
            if(!res) res += N;
            cout << res << "\n";
            v = (v * res) % N;
        }
    }

    cout.flush();
    return 0;
}