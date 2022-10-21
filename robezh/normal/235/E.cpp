#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 2050, mask = (1 << 30) - 1;
//, mod = 1073741824;

bool p[M];
int mu[M], pm[M], phi[M], pms;

void get_mobius_and_sieve(){
    mu[1] = 1;
    phi[1] = 1;
    fill(p, p + M, true);
    pms = 0;
    for(int i = 2; i < M; i++){
        if(p[i]){
            pm[pms++] = i;
            mu[i] = -1;
            phi[i] = i - 1;
        }
        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = false;
            if(i % pm[j] == 0){
                mu[i * pm[j]] = 0;
                phi[i * pm[j]] = phi[i] * pm[j];
                break;
            }
            mu[i * pm[j]] = -mu[i];
            phi[i * pm[j]] = phi[i] * (pm[j] - 1);
        }
    }
}

int a, b, c;
int g[M][M];

int main() {
    get_mobius_and_sieve();
    for(int i = 1; i < M; i++) for(int j = 1; j < M; j++) g[i][j] = __gcd(i, j);

    cin >> a >> b >> c;
    int res = 0;
    for(int i = 1; i <= a; i++) {
        int sum = 0;
        for(int d = 1; d <= min(b, c); d++) {
            int sum1 = 0;
            for(int j = 1; j * d <= b; j++) sum1 += (b / (j * d)) * (g[i][j*d] == 1);
            int sum2 = 0;
            for(int k = 1; k * d <= c; k++) sum2 += (c / (k * d)) * (g[i][k*d] == 1);
            sum += mu[d] * sum1 * sum2;
        }
        res += (a / i) * sum;
    }
    cout << (res & mask) << endl;

}