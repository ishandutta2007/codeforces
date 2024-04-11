#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int x,y;
LL Lcnt[100010][3],Rcnt[100010][3];
char s[100010];
LL val[100010][2], S[100010][2];
int N;
vector<int>p;

int main() {
    scanf("%s", s + 1);
    scanf("%d%d",&x,&y);
    N = strlen(s + 1);
    for (int i=1;i<=N;i++) {
        if (s[i] == '?') s[i] = '2';
        Lcnt[i][0] = Lcnt[i-1][0];
        Lcnt[i][1] = Lcnt[i-1][1];
        Lcnt[i][2] = Lcnt[i-1][2];
        Lcnt[i][s[i] - '0']++;
    }
    for (int i=N;i>=1;i--) {
        Rcnt[i][0] = Rcnt[i+1][0];
        Rcnt[i][1] = Rcnt[i+1][1];
        Rcnt[i][2] = Rcnt[i+1][2];
        Rcnt[i][s[i] - '0']++;
    }
    LL ans;
    LL s0 = 0;
    for (int i=1;i<=N;i++) {
        if (s[i] == '1') {
            s0 += 1LL * x * Lcnt[i - 1][0];
        } 
        if (s[i] == '0') {
            s0 += 1LL * y * Lcnt[i - 1][1];
        }
    }
    for (int i=1;i<=N;i++) {
        if (s[i] != '2') val[i][0] = val[i][1] = 0;
        else {
            val[i][0] = 1LL * x * Rcnt[i + 1][1] + 1LL * y * Lcnt[i - 1][1];
            val[i][1] = 1LL * y * Rcnt[i + 1][0] + 1LL * x * Lcnt[i - 1][0];
        }
        S[i][0] = S[i-1][0] + val[i][0];
        S[i][1] = S[i-1][1] + val[i][1];
    }
    ans = 1e18;
    LL tmp = 0;
    for (int i=1;i<=N+1;i++) {
        // 10
        ans = min(ans, s0 + 1LL * Lcnt[i - 1][2] * Rcnt[i][2] * y + S[i - 1][1] + S[N][0] - S[i - 1][0]);
        // 01
        ans = min(ans, s0 + 1LL * Lcnt[i - 1][2] * Rcnt[i][2] * x + S[i - 1][0] + S[N][1] - S[i - 1][1]);
    }
    printf("%lld\n",ans);
}