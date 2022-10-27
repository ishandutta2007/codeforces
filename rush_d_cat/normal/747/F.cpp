#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 16;
LL n, k;
LL dp[2*N][2*N], c[2*N][2*N];
void init() {
    for (int i=0;i<N;i++) c[i][0] = 1;
    for (int i=1;i<N;i++)
        for (int j=1;j<N;j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
}

LL cac(int len, vector<int> limit, bool lead_zero) {

    if (lead_zero == 0 && limit[0]) {
        LL ans = 0;

        for (int i = 1; i < N; i ++) {
            if (limit[i]) {
                limit[i] --;
                ans += cac(len-1, limit, 1);
                //printf("%d %lld\n", i, cac(len-1,limit,1));
                limit[i] ++;
            }
        }
        return ans;
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= limit[0]; i ++)
        dp[0][i] = 1;

    for (int i = 0; i < N-1; i ++)
        for (int j = 0; j < N; j ++) {
            for (int k = 0; k <= limit[i+1]; k ++) {
                dp[i+1][j+k] += dp[i][j] * c[j+k][j];
            }
        }

    return dp[15][len];
}

void JUDGEMENT() {
    vector<int> limit;
    for (int i=0;i<=15;i++) limit.push_back(2);
    //limit[1]=1;
    //cout << cac(3,limit,0) << endl; //exit(0);
}

int main() {
    init();

    cin >> n >> k;
    vector<int> limit;
    for (int i=0;i<=15;i++) limit.push_back(k);

    LL sum = 0, len = 1;
    for (len = 1; sum < n; len ++) {
        //printf("len = %lld, cac = %lld, sum = %lld\n", len, cac(len, limit, 0), sum);
        if (sum+cac(len,limit,0) >= n) break;
        sum += cac(len,limit,0);
    }
    
    sum = n - sum;
    //printf("len=%lld, sum=%lld\n", len, sum);

    vector<int> ans;

    for (int pos = 1; pos <= len; pos ++) {
        LL tmp = 0;
        for (int i = ((pos==1)?1:0); i<=15; i++) {
            if (limit[i] == 0) continue;
            limit[i] --;
            if (tmp + cac(len-pos,limit,1) >= sum) {
                ans.push_back(i);
                sum = sum - tmp;
                break;
            }
            tmp += cac(len-pos,limit,1);
            limit[i] ++;
        }
    }
    for (int i = 0; i < ans.size(); i ++) {
        printf("%c", ans[i]<=9 ? '0'+ans[i] : 'a'+ans[i]-10);
    }
}