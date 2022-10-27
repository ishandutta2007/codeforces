#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int prime[N], cnt = 0;
bool vis[N]; 
int phi[N], mius[N];
LL sum[N];
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
}
int n,k;
bool visit[N];
vector<int> divs[N];
int main() {
    scanf("%d%d",&n,&k);
    if(k==1) {
        printf("3\n"); return 0;
    }
    getPrime();
    sort(phi+1, phi+1+n);
    LL ans=0;
    for(int i=1;i<=k+2;i++) ans += phi[i];
    printf("%lld\n", ans);
}