#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000000+10;
int prime[N], cnt = 0;
bool vis[N]; 
int phi[N], mius[N], ans[N];

void getPrime() {
    phi[1] = 1, mius[1] = 1;
    for (int i = 2; i < N; i ++) {
        if (vis[i] == 0) {
            prime[++ cnt] = i;
            phi[i] = i - 1;
            mius[i] = -1;
        }
        for (int j = 1; j <= cnt && prime[j] * i < N; j ++) {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0) {           
                mius[prime[j] * i] = 0;
                phi[prime[j] * i] = phi[i] * prime[j];
                break;
            } else {
                mius[prime[j] * i] = mius[i] * -1;
                phi[prime[j] * i] = phi[i] * (prime[j] - 1);
            }
        }
    }
    prime[0] = 1;
    for (int i = 0; i <= cnt; i ++) {
        for (int j = prime[i]*2; j < N; j += prime[i]) {
            ans[j] = prime[i];
        }
    }
}

int x;
int main() {
    getPrime();
    cin >> x;
    int res = x;
    for (int i = x - ans[x] + 1; i <= x; i ++)
    {
        res = min(res, i - ans[i] + 1);
    }
    printf("%d\n", res);

}