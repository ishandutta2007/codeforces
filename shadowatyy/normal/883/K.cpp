#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int n;
int s[200007], g[200007];
ii pom[200007];
bool vis[200007];
ll res = 0;
bool ok = true;
set<ii> S;

int main() {
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++) {
        scanf("%d %d", &s[i], &g[i]);
        g[i] = s[i] + g[i];
        pom[i] = {g[i], i};
        S.insert({g[i], i});
    }

    for(int i = 0 ; i < n ; i++) {
        ii p = *(S.begin());
        S.erase(S.begin());

        vis[p.second] = true;
        if(p.second > 0 && !vis[p.second - 1]) {
            S.erase({g[p.second - 1], p.second - 1});
            g[p.second - 1] = min(g[p.second - 1], g[p.second] + 1);
            S.insert({g[p.second - 1], p.second - 1});
        }
        if(p.second < n - 1 && !vis[p.second + 1]) {
            S.erase({g[p.second +1], p.second + 1});
            g[p.second + 1] = min(g[p.second + 1], g[p.second] + 1);
            S.insert({g[p.second +1], p.second + 1});
        }

    }

   // for(int i = 0 ; i  <n;i++)
  //      printf("%d ", g[i]);
  //  printf("\n");

    for(int i = 0 ; i < n ; i++) {
        if(g[i] < s[i]) {
            printf("-1\n");
            return 0;
        }
        res += ll(g[i] - s[i]);
    }

    printf("%I64d\n", res);

    for(int i = 0 ;i  < n ; i++) {
        printf("%d", g[i]);
        if(i < n - 1)
            printf(" ");

    }
    printf("\n");

    return 0;
}