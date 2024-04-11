#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const int DIM = 17;
struct M
{
    LL num[DIM][DIM];
};
M O, E;
void init()
{
    for(int i=0;i<DIM;i++)
    {
        for(int j=0;j<DIM;j++)
        {
            O.num[i][j] = 0;
            E.num[i][j] = (i==j)?1:0;
        }
    }
}
M mul(M A, M B)
{
    M C = O;
    for(int i=0;i<DIM;i++) 
    {
        for(int j=0;j<DIM;j++) 
        {     
            for(int k=0;k<DIM;k++)
            {
                C.num[i][j] += A.num[i][k] * B.num[k][j];
                C.num[i][j] %= MOD;
            }
        }
    }
    return C;
}
M mpow(M a, LL n)
{
    M ret = E;
    while(n)
    {
        if(n & 1)
        {
            ret = mul(ret, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return ret;
}


LL n, k;
LL a[102], b[102], c[102];
LL ans[16]; M mat;

void solve(LL t, LL h) {
    mat = O;
    mat.num[0][0] = mat.num[0][1] = 1;
    for(int i=1;i<15;i++) {
        mat.num[i][i-1] = mat.num[i][i] = mat.num[i][i+1] = 1;
    }
    mat.num[15][15] = mat.num[15][14] = 1;
    for(int i=0;i<=15;i++) {
        for(int j=0;j<=15;j++) {
            if(i > h || j > h) {
                mat.num[i][j] = 0;
            }
        }
    }
    mat = mpow(mat, t);
    LL tmp[16]; 
    for(int i=0;i<=15;i++) {
        tmp[i] = ans[i];
        ans[i] = 0;
    }
    for(int i=0;i<=15;i++) {
        for(int j=0;j<=15;j++) {
            ans[i] += mat.num[i][j] * tmp[j] % MOD;
            ans[i] %= MOD;
        }
    }


}


int main() {
    init();
    scanf("%lld %lld", &n, &k);
    for(int i=1;i<=n;i++) {
        scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
    }
    b[n] = k; ans[0] = 1;
    for(int i=1;i<=n;i++) {
        solve(b[i] - a[i], c[i]);
    }
    cout << ans[0] << endl;
}