#include <bits/stdc++.h>
using namespace std;

const int D = (int)2;
int mod;
typedef long long ll;
typedef unsigned long long ull;

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

struct matrix
{
    int size;
    ll a[D][D];
    void init(int _size = -1){
        if(_size != -1) size = _size;
        memset(a, 0, sizeof(a));
    }
    matrix(int _size = -1){
        (*this).init(_size);
    }
    void set_identity(){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++) a[i][j] = (ll)(i == j);
        }
    }
    matrix operator * (const matrix &B) const
    {
        matrix C = matrix(size);

        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++){
                for(int k = 0; k < size; k++)
                    C.a[i][j] += a[i][k] * B.a[k][j] % mod;
                C.a[i][j] %= mod;
            }
        return C;
    }

    matrix operator ^ (const ll &p) const
    {
        matrix A = (*this), res = matrix(A.size);
        res.set_identity();
        ll t = p;
        while(t > 0)
        {
            if(t % 2) res = res * A;
            A = A * A;
            t /= 2;
        }
        return res;
    }
} mat;

ll count(ll n) {
    mat.size = 2;
    mat.a[0][0] = 0;
    mat.a[0][1] = mat.a[1][0] = mat.a[1][1] = 1;
    mat = mat ^ (n - 1);
    return (2 * mat.a[0][0] + 3 * mat.a[0][1]) % mod;
}

ll n, k, l;

int main() {
    cin >> n >> k >> l >> mod;

    ll cnt0 = count(n), cnt1 = (fp(2, n) - cnt0) % mod;

    ll res = 1;
    for(int i = 0; i < l; i++) {
        if(k % 2 == 0) res = (res * cnt0) % mod;
        else res = (res * cnt1) % mod;
        k /= 2;
    }
    if(k > 0) res = 0;
    cout << (res % mod + mod) % mod << endl;
}