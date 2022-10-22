#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    int T;
    scanf("%d",&T);
    const int B = 30;
    const int M = 200000;
    vector<vector<int>> cnt(M + 1, vector<int>(B, 0));
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < B; j++) {
            cnt[i][j] = cnt[i - 1][j];
            if ((i >> j) & 1) cnt[i][j]++;
        }
    }
    while(T--) {
        int n;
        int ans = 1e9;
        int L, R;
        scanf("%d%d",&L,&R);
        int len = R - L + 1;
        for (int i = 0; i < B; i++) {
            int val = cnt[R][i] - cnt[L - 1][i];
            if (val == 0) continue;
            ans = min(ans, len - val);
        }
        printf("%d\n",ans);
    }
}