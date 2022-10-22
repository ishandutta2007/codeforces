#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
int d[2010][2010];
void query(int x) {
    printf("? %d\n",x);
    fflush(stdout);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&d[x][i]);
    }
}

vector<pii> ans;

int main() {
    scanf("%d",&n);
    query(1);
    int cnt[2] = {0, 0};
    for (int i = 1; i <= n; i++ ){
        cnt[d[1][i] % 2]++;
    }
    int par = (cnt[0] <= cnt[1]) ? 0 : 1;
    for (int i = 1; i <= n; i++) {
        if (d[1][i] % 2 == par) {
            if (i != 1) query(i);
            for (int j = 1; j <= n; j++) {
                if (d[i][j] == 1) ans.push_back(pii(i, j));
            }
        }
    }
    puts("!");
    for (auto &t : ans) {
        printf("%d %d\n",t.first,t.second);
    }
    fflush(stdout);
}