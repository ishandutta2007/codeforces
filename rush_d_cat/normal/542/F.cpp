#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 2002;
typedef long long LL;
int n, T;
struct Item {
    int t, q;
} it[N];
bool cmp(int x, int y) {
    return x > y;
}
vector<int> vec[N];
int dp[102][N];

int main() {
    int ans = 0;
    scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &it[i].t, &it[i].q);
        vec[it[i].t].push_back(it[i].q);
        if (it[i].t == T) ans = max(ans, it[i].q);
    }
    for (int i = 0; i < 102; i ++) for (int j = 0; j <= n; j ++) dp[i][j] = - 1e9;
    dp[0][1] = 0; 

    for (int dep = 0; dep < T; dep ++) {
        int id = T - dep - 1;
        sort(vec[id].begin(), vec[id].end(), cmp);

        for (int i = 0; i <= n; i ++) {
            //printf("dp[%d][%d] = %d\n", dep, i, dp[dep][i]);
            LL qsum = 0;
            for (int j = -1; j < (int)vec[id].size(); j ++) {
                if (j >= 0) qsum = qsum + vec[id][j];
                //printf("i = %d, j = %d\n", i, j);
                int cnt = j + 1;
                int rem = min(2 * i - cnt, n);
                //printf("%d %d\n", dep+1, rem);
                if (rem >= 0) dp[dep+1][rem] = max(dp[dep+1][rem], dp[dep][i] + (int)qsum);
            }
        }
    }

   
    for (int i = 0; i <= n; i ++) ans = max(ans, dp[T][i]);
    cout << ans << endl;
}