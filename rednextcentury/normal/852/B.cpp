#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (1000000007)
long long add(long long a, long long b)
{
    long long res = a + b;
    if(res >= MOD)
        return res - MOD;
    return res;
}

long long mult(long long a, long long b)
{
    long long res = a;
    res *= b;
    if(res >= MOD)
        return res % MOD;
    return res;
}
#define SZ 100
struct matrix
{
    long long arr[SZ][SZ];

    void reset()
    {
        memset(arr, 0, sizeof(arr));
    }

    void makeiden()
    {
        reset();
        for(long long i=0;i<SZ;i++)
        {
            arr[i][i] = 1;
        }
    }

    matrix operator + (const matrix &o) const
    {
        matrix res;
        for(long long i=0;i<SZ;i++)
        {
            for(long long j=0;j<SZ;j++)
            {
                res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
            }
        }
        return res;
    }

    matrix operator * (const matrix &o) const
    {
        matrix res;
        for(long long i=0;i<SZ;i++)
        {
            for(long long j=0;j<SZ;j++)
            {
                res.arr[i][j] = 0;
                for(long long k=0;k<SZ;k++)
                {
                    res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
                }
            }
        }
        return res;
    }
};

matrix power(matrix a, long long b)
{
    matrix res;
    res.makeiden();
    while(b)
    {
        if(b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
long long N1[1000000];
long long N2[1000000];
long long N3[1000000];
ll W1[1000000];
ll num[1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, l, m;
    cin >> n >> l >> m;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        x %= m;
        W1[i]=x;
        N1[x]++;
    }
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        x %= m;
        W1[i]=x;
        N2[x]++;
    }
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        x+=W1[i];
        x %= m;
        N3[x]++;
    }
    matrix X;
    X.reset();
    for (long long i=0;i<100;i++){
        for (long long j=0;j<100;j++){
            X.arr[i][(i+j)%m]+=N2[j];
            X.arr[i][(i+j)%m]%=MOD;
        }
    }
    X = power(X, l-2);
    for (long long i=0;i<m;i++){
        for (long long j=0;j<m;j++){
            num[j]+=(N1[i]*X.arr[i][j])%MOD;
            num[j]%=MOD;
        }
    }
    ll ret=0;
    for (long long i=0;i<m;i++){
        ret+=(num[i]*N3[(m-i)%m])%MOD;
        ret%=MOD;
    }
    cout<<ret<<endl;
}