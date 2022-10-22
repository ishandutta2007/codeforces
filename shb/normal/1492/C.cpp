#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[200010], t[200010];
int match1[200010], match2[200010];

int main() {
    scanf("%d%d",&n,&m);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int node = 1;
    for (int i=1;i<=n;i++) {
        if (s[i] == t[node]) {
            match1[node] = i;
            node++;
            if (node > m) break;
        }
    }
    node = m;
    for (int i=n;i>=1;i--) {
        if (s[i] == t[node]) {
            match2[node] = i;
            node--;
            if (node <= 0) break;
        }
    }
    /*
    for (int i=1;i<=m;i++) {
        printf("%d %d\n",match1[i], match2[i]);
    }
    */
    int ans = 0;
    for (int i=1;i<m;i++) {
        ans = max(ans, match2[i + 1] - match1[i]);
    }
    printf("%d\n",ans);
}