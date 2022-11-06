#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 55;

int cnt[sz], ans[sz][sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, m, a, b;
        scanf("%d %d %d %d", &n, &m, &a, &b);
        memset(ans, 0, sizeof(ans));
        memset(cnt, 0, sizeof(cnt));

        for(int i=0, k=0; i<n; i++) {
            for(int j=0; j<a; j++, k++) {
                if(k == m) k = 0;
                ans[i][k] = 1;
                cnt[k]++;
            }
        }

        bool no = 0;
        for(int i=0; i<m; i++) if(cnt[i] ^ b) no = 1;

        if(no) puts("NO");
        else {
            puts("YES");
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) printf("%d", ans[i][j]);
                puts("");
            }
        }
    }
}