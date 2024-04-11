#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N = (int)1e5 + 50, mod = (int)1e9 + 7;


int n;
ll num[N];
bool is_odd[N];
ll pprod[N];
ld p = 1;

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll inv(ll x) {
    return fp(x, mod - 2);
}

ll get_pow(ll x, ll pw) {
    if(pw < 0) pw += (mod - 1);
    return fp(x, pw);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
        is_odd[i] = (num[i] % 2 == 1);
        p *= num[i];
    }
    if(p <= 2) {
        if(p == 0) cout << "1/1" << endl;
        else if(p == 1) cout << "0/1" << endl;
        else cout << "1/2" << endl;
        return 0;
    }
    pprod[0] = 1;
    for(int i = 1; i <= n; i++) pprod[i] = pprod[i-1] * (num[i] % (mod - 1)) % (mod - 1);
    ll tn = 0;
    int odd = 1;
    for(int i = n; i >= 1; i--) {
        tn += pprod[i-1] * (num[i] / 2 % (mod - 1)) % (mod - 1);
        tn %= (mod - 1);
        if(num[i] % 2 == 0) {
            odd = 0;
            break;
        }
    }
    ll nom, denom;
    if(!odd) {
        nom = (2 * get_pow(4, tn - 1) + 1) * inv(3) % mod;
        nom = (nom % mod + mod) % mod;
        denom = 2 * get_pow(4, tn - 1) % mod;
    }
    else {
        nom = 2 * get_pow(4, tn - 1) % mod - (2 * get_pow(4, tn - 1) + 1) * inv(3) % mod;
        nom = (nom % mod + mod) % mod;
        denom = get_pow(4, tn);
    }
    cout << nom << "/" << denom << endl;

}