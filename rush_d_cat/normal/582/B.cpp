#include <iostream>
#include <set> 
#include <cstring>
#include <algorithm>
using namespace std;

int n, t;
int a[102];
int dp[102][102], f[102];
int ans[102][102], cnt[302];
int ord[102], rk[302];

set<int> st;

int main() {
    scanf("%d %d", &n, &t);

    int cnt_max = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]); cnt[a[i]] ++;  st.insert(a[i]);
        cnt_max = max(cnt_max, cnt[a[i]]);
    }

    set<int>::iterator it; int id = 0;
    for(it = st.begin(); it != st.end(); it ++) {
        ord[++id] = *it; rk[*it] = id;
    }

    for(int x = 1; x <= id; x ++) 
    {
        a[0] = ord[x];

        memset(f, 0, sizeof(f)); 
        
        for(int i = 1; i <= n; i ++) { 
            for(int k = 0; k < i; k ++) {
                if(a[i] < a[0]) continue;
                if(a[i] >= a[k] && a[k] >= a[0]) {
                    f[i] = max(f[i], f[k] + 1);
                }
            }
        }

        for(int i = 1; i <= n; i ++) {
            dp[x][rk[a[i]]] = max(f[i], dp[x][rk[a[i]]]);
        }

    }

    for(int j = 1; j <= id; j ++) {
        ans[1][j] = dp[1][j];
    }

    for(int i = 2; i <= id; i ++) {
        for(int j = 1; j <= id; j ++) {
            for(int k = 1; k <= j; k ++) {
                ans[i][j] = max(ans[i-1][k] + dp[k][j], ans[i][j]);
            }
        }
    }

    int res = 0;

    for(int i = 1; i <= id; i ++) {
        res = max(res, ans[min(t, id)][i]);
    }

    if(t >= id) {
        res += (t - id) * cnt_max;
    }

    cout << res << endl;

}