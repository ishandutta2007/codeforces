//B
#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 2011
#define inf 1000000000000000000LL
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;
typedef pair <int, int> pii;
pii p[N];

int n;
int cnt[N];
ll tot[N][N];
ll ans[N][N];

int main(){
    //freopen("b.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d %d", &p[i].first, &p[i].second);
        cnt[p[i].first] ++;
    }
    sort(p, p + n);

    int r = 0;
    for(int i = 0; i < N; i ++){
        tot[i][0] = 0;
        for(int j = 0; j < cnt[i]; j ++){
            tot[i][j + 1] = tot[i][j] + p[r + j].second;
        }
        r += cnt[i];
    }

    for(int i = 0; i < N; i ++) ans[i][0] = 0;
    for(int i = 1; i <= n; i ++){
        if(i <= cnt[0]) ans[0][i] = tot[0][i];
        else ans[0][i] = inf;
    }
    for(int i = 1; i < N; i ++) {
        for(int j = 1; j <= n; j ++){
            ans[i][j] = inf;
            for(int k = 0; k <= cnt[i]; k ++){
                ans[i][j] = min(ans[i][j], ans[i - 1][max(0, j - k - i * k)] + tot[i][k]);
            }
        }
    }


    ll rlt = inf;
    for(int i = 0; i < N; i ++) rlt = min(rlt, ans[i][n]);

    printf("%I64d\n", rlt);
}