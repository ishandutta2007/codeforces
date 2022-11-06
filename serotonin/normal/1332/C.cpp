#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int n,k;
char s[sz];
bitset <sz> vis;

int cnt[30];

void dfs(int u)
{
    if(u>=n) return;
    if(vis[u]) return;
    vis[u] = 1;
    cnt[s[u]-'a']++;
    dfs(u+k);
    dfs(n-1-u);
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        scanf("%d %d", &n, &k);
        scanf("%s", s);
        for(int i=0; i<n; i++) vis[i]=0;

        int ans = 0;
        for(int i=0; i<k; i++) {
            if(!vis[i]) {
                dfs(i);

                int now = 0, sum = 0;
                for(int i=0; i<30; i++) {
                    now = max(now, cnt[i]);
                    sum += cnt[i];
                    cnt[i] = 0;
                }

                ans += sum - now;
            }
        }

        printf("%d\n", ans);
    }
}