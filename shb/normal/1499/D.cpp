#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

vector<int>prime;
const int M = 20000000;
int mi[M + 10], cnt[M + 10];
bool ok[M + 10];
int c, d, x;

LL solve(int x) {
    if ((x + d) % c != 0) return 0;
    x = (x + d) / c;
    return (1LL << cnt[x]);
}

int main() {
    memset(ok, true, sizeof(ok));
    for (int i=2;i<=M;i++) {
        if (ok[i]) {
            prime.push_back(i);
            mi[i] = i;
            cnt[i] = 1;
        }
        for (int j=0;j<prime.size() && i * prime[j] <= M;j++) {
            ok[i * prime[j]] = false;
            mi[i * prime[j]] = prime[j];
            cnt[i * prime[j]] = cnt[i] + 1;
            if (i % prime[j] == 0) {
                cnt[i * prime[j]]--;
                break;
            }
        }
    }
    /*
    for (int i=0;i<=100;i++) {
        printf("%d %d %d %d\n",i,prime[i],mi[i],cnt[i]);
    }
    */
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&c,&d,&x);
        LL ans = 0;
        for (int g=1;g*g<=x;g++) {
            if (x % g == 0) {
                ans += solve(g);
                if (g*g != x) ans += solve(x / g);
            }
        }
        printf("%lld\n",ans);
    }

}