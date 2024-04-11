#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int D = (int)16, mod = (int)1e9 + 7;
typedef long long ll;

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
};

int n;
ll k;
ll a[N], b[N];
int c[N];
ll dp[D];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    b[n] = min(b[n], k);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        ll new_dp[D];
        for(int j = c[i] + 1; j < D; j++) dp[j] = 0;
        memset(new_dp, 0, sizeof(new_dp));
        matrix A;
        A.init(c[i] + 1);
        for(int j = 0; j < c[i] + 1; j++) {
            if(j - 1 >= 0) A.a[j-1][j] = 1;
            A.a[j][j] = 1;
            if(j + 1 < c[i] + 1) A.a[j+1][j] = 1;
        }
        A = A ^ (b[i] - a[i]);
        for(int j = 0; j < c[i] + 1; j++) {
            for(int k = 0; k < c[i] + 1; k++) {
                new_dp[j] += A.a[j][k] * dp[k] % mod;
                new_dp[j] %= mod;
            }
        }
        for(int j = 0; j < D; j++) dp[j] = new_dp[j];
    }
    cout << dp[0] << endl;
}