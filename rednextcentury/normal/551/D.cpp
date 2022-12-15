#include <bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;
const int K = 2;

long long mod=1000000;
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

matrix pow(matrix A, long long p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}
ll P(ll A, ll p)
{
    if (p == 1)
        return A;
    ll x = P(A,p/2);
    x = (x*x)%mod;
    if (p%2)x=(x*A)%mod;
    return x;
}
long long fib(long long N)
{
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = 2;
    F1[2] = 3;

    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;

    // raise T to the (N-1)th power
    if (N == 1)
        return 2;
    T = pow(T, N-1);

    // the answer is the first row of T . F1
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % mod;
    return res;
}

int main()
{
    long long n,k,l;
    cin>>n>>k>>l>>mod;
    long long zer = fib(n);
    long long one = (P(2,n)-zer+mod)%mod;
    ll ret=(1%mod);
    if (l<=60 && (1LL<<l)<=k)
        ret=0;
    for (long long i=0;i<l;i++)
    {
        if (i>=60)ret=(ret*zer)%mod;
        else if ((1LL<<i)&k) ret=(ret*one)%mod;
        else ret=(ret*zer)%mod;
    }
    cout<<ret%mod<<endl;
}