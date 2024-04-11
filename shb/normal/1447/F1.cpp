#include <bits/stdc++.h>

using namespace std;

int N;
int a[200010];
int cnt[200010];
int S[200010];
const int BIAS = 200000;
int pos[400040];

int main() {
    scanf("%d",&N);
    int mx = 0;
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        mx = max(mx, cnt[a[i]]);
    }
    int max_id = -1;
    for (int i=1;i<=N;i++) {
        if (cnt[i] == mx) {
            if (max_id != -1) {
                printf("%d\n",N);
                return 0;
            }
            max_id = i;
        }
    }
    for (int j=-N;j<=N;j++) {
        pos[j+BIAS] = -1;
    }
    int ans = 0;
    for (int i=1;i<=N;i++) {
        if (i == max_id || cnt[i] == 0) continue;
        bool have = false;
        pos[BIAS] = 0;
        for (int j=1;j<=N;j++) {
            S[j] = S[j - 1];
            if (a[j] == max_id) S[j]++, have = true;
            if (a[j] == i) S[j]--, have = true;
            if (!have) continue;
            if (pos[S[j] + BIAS] == -1) {
                pos[S[j] + BIAS] = j;
            } else {
                ans = max(ans, j - pos[S[j] + BIAS]);
            }
        }
        for (int j=-N;j<=N;j++) {
            pos[j+BIAS] = -1;
        }
    }
    printf("%d\n",ans);
}