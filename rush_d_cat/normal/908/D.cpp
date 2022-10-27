#include <iostream>
using namespace std;
typedef long long LL;
const int N = 2002;
const LL MOD = 1000000007;

LL k, pa, pb;
LL dp[N][N];
double hsg[N][N];

LL mpow(LL a, LL x) {
    if (x == 0) return 1;
    LL t = mpow(a, x / 2);
    if (x % 2)
        return t * t % MOD * a % MOD;
    return t * t % MOD;
}

LL inv(LL x) {
    return mpow(x, MOD-2);
}

int main() {
    //printf("%lld\n", 5*inv(4)%MOD);
    cin >> k >> pa >> pb;

    for (int i = 2 * k; i >= 0; i --) {
        for (int j = k; j >= 1; j --) {
            if (i >= k) {
                dp[i][j] = i; hsg[i][j] = i;
                            //printf("hsg[%d][%d] = %.5f\n", i, j, hsg[i][j]);
                continue;
            }
            if (i+j >= k) {
                //dp[i][j] = (pa + pb) * inv(pb) % MOD;

                dp[i][j] = i+j + pa*inv(pb)%MOD; // i:ab, j: a  (pa+pb)/pa
                /*

            
                q = pa / (pa + pb)
                
                0 * p
                1 * q * p
                2 * q * q * p
                3 * q * q * q * p

                p
                q + 2*q*q + 3*




                q*q




                */




                hsg[i][j] = i + 1.0 * (pa + pb) / pb;
                //printf("hsg[%d][%d] = %.5f\n", i, j, hsg[i][j]);
                continue;
            }
            dp[i][j] = (pa * dp[i][j+1] + pb * dp[i+j][j]) % MOD * inv(pa+pb) % MOD;
            hsg[i][j] = (pa * hsg[i][j+1] + pb * hsg[i+j][j]) / (pa+pb) ;
            //printf("hsg[%d][%d] = %.5f\n", i, j, hsg[i][j]);
        }
    }
    //printf("%.6f\n", hsg[0][1]);
    printf("%lld\n", dp[0][1]);
}