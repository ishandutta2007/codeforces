#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
LL c[101010];
LL mi[101010],s[101010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%lld",&c[i]);
        }
        mi[1] = c[1];
        mi[2] = c[2];
        s[1] = c[1];
        s[2] = c[2];
        for (int i=3;i<=N;i++) {
            mi[i] = min(c[i], mi[i - 2]);
            s[i] = s[i - 2] + c[i];
        }
        LL ans = 1e18;
        for (int i=2;i<=N;i++) {
            int cnt1 = i / 2 + i % 2;
            int cnt2 = i / 2;
            LL tmp_ans = mi[i] * (N - cnt1) + s[i]
                       + mi[i - 1] * (N - cnt2) + s[i - 1];
            ans = min(ans, tmp_ans);
        }
        printf("%lld\n",ans);
    }
}