#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5 + 500;

int p[M];
vector<int> pms;

void setup_primes(){
    for(int i = 0; i < M; i++) p[i] = i;
    for(int i = 2; i < M; i++){
        if(p[i] != i) continue;
        pms.push_back(i);
        for(int j = i * 2; j < M; j += i) p[j] = i;
    }
}

int a, b, c;
int fac[M];
int bits[70];
int permu[6][3] = {{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}};

int main(){
    setup_primes();
    for(int i = 1; i < M; i++){
        int t = i, cur = 0;
        fac[i] = 1;
        while(t > 1){
            cur = 0;
            int cpm = p[t];
            while(t % cpm == 0){
                cur ++;
                t /= cpm;
            }
            fac[i] *= (cur + 1);
        }
    }
    for(int i = 0; i < 70; i++){
        int t = i;
        while(t > 0){
            bits[i] += t % 2; t /= 2;
        }
    }

    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &a, &b, &c);
        int res1 = fac[__gcd(__gcd(a, b), c)];

        int g[8];
        g[1] = fac[a], g[2] = fac[b], g[4] = fac[c];
        g[3] = fac[__gcd(a, b)], g[6] = fac[__gcd(b, c)], g[5] = fac[__gcd(c, a)];
        g[7] = res1;

        int res2 = g[1] * g[6] + g[2] * g[5] + g[4] * g[3] - g[7] * (g[3] + g[5] + g[6])
                   + g[7] * g[7] - g[7];

        int num[3] = {a, b, c};
        int restot = 0;
        for(int i = 1; i < (1 << 6); i++){
            int cur[3] = {0, 0, 0};
            for(int j = 0; j < 6; j++){
                if((1 << j) & i){
                    for(int t = 0; t < 3; t++) cur[t] |= (1 << permu[j][t]);
                }
            }
            restot += (bits[i] % 2 ? 1 : -1) * g[cur[0]] * g[cur[1]] * g[cur[2]];
        }
//        cout << restot << endl;
        restot -= res1 + res2 * 3;
        restot /= 6;
        printf("%d\n", restot + res1 + res2);
    }

}