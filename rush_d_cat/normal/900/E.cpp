#include <iostream>
#include <cstring>
using namespace std;
const int N = 1000000+10;
typedef pair<int, int> pii;

int n, m;
int sa[N][2], sb[N][2];
char s[N];
pii dp[N];

int main() {
    scanf("%d %s %d", &n, s+1, &m);

    for (int i = 1; i <= n; i ++) {
        
        sa[i][0] = sa[i-1][0];
        sa[i][1] = sa[i-1][1];
        sb[i][1] = sb[i-1][1];
        sb[i][0] = sb[i-1][0];

        if (s[i] == 'a') {
            sa[i][i%2] ++;
        } 
        if (s[i] == 'b') {
            sb[i][i%2] ++;
        }
    }

    for (int i = 0; i < N; i ++)
        dp[i] = make_pair(-1e9, 1e9);
    dp[0] = make_pair(0, 0);

    for (int i = 0; i < n; i ++) {
        if (dp[i].first > dp[i+1].first || (dp[i].first == dp[i+1].first && dp[i].second < dp[i+1].second))
            dp[i+1] = dp[i];

        int cnt = 0; bool flag = 1;
        if (i+m>n) continue;
        if ((i+1)%2) {
            if ((sb[i+m][1] - sb[i][1]) || (sa[i+m][0] - sa[i][0]))
                flag = 0;
                            
            cnt = m - (sb[i+m][0] - sb[i][0]) - (sa[i+m][1] - sa[i][1]);
        } else {
            if ((sb[i+m][0] - sb[i][0]) || (sa[i+m][1] - sa[i][1]))
                flag = 0;
            cnt = m - (sb[i+m][1] - sb[i][1]) - (sa[i+m][0] - sa[i][0]);
        }

        if (!flag) continue;
        if ((dp[i].first + 1 > dp[i+m].first) || (dp[i].first + 1 == dp[i+m].first && dp[i].second+cnt < dp[i+m].second))
            dp[i+m] = make_pair(dp[i].first+1, dp[i].second+cnt);
    }

    /*
    for (int i=1;i<=n;i++) {
        printf("%d %d\n", dp[i].first, dp[i].second);
        printf("pos = %d\n", );
    }
    */


    printf("%d\n", dp[n].second);
}