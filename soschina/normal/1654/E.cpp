#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
const int N = 1e5 + 1, M = 316;

int n, a[N], bucket[N * M * 2 + N], *cnt = bucket + N * M, ans;
map<int, int> dp[N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int d = -M; d <= M; d++){
        for(int i = 1; i <= n; i++){
            cnt[a[i] + i * d]++;
            ans = max(ans, cnt[a[i] + i * d]);
        }
        for(int i = 1; i <= n; i++)
            cnt[a[i] + i * d]--;
    }
    for(int i = 2; i <= n; i++)
        for(int j = max(i - M, 1); j < i; j++){
            int d = (a[i] - a[j]) / (i - j);
            if(d * (i - j) == a[i] - a[j]){
                dp[i][d] = dp[j][d] + 1;
                ans = max(ans, dp[i][d] + 1);
            }
        }
    printf("%d", n - ans);
    return 0;
}