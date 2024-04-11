#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 100000 + 10;
int n, m, f[N][2];
int main() {
    scanf("%d%d",&n,&m);
    f[1][0]=2;
    for(int i=2;i<N;i++){
        f[i][0]=(f[i-1][0]+f[i-1][1])%MOD;
        f[i][1]=f[i-1][0];
    }
    LL ans = (f[m][0]+f[m][1]-2) % MOD;
    ans = (ans + f[n][0] + f[n][1]) % MOD;
    cout << ans << endl;
}