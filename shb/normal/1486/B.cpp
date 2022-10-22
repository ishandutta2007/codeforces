#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

typedef long long LL;

int main() {
    int T, N;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        vector<LL> x, y;
        for (int i=1;i<=N;i++) {
            LL tx, ty;
            scanf("%lld%lld",&tx,&ty);
            x.push_back(tx);
            y.push_back(ty);
        }
        if (N % 2 == 1) {
            puts("1");
            continue;
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int id = N / 2 - 1;
        LL dx = x[id + 1] - x[id] + 1;
        LL dy = y[id + 1] - y[id] + 1;
        printf("%lld\n",dx * dy);
    }
}