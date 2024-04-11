#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, INF = (int)1e9;
typedef pair<int, int> P;

int n, len;
int num[N];
int dp[N];
int pl[N], pr[N];
int cnt[N];

bool ok(int i){
    return pr[i] + pl[i] - 1 == len;
}

int get_LIS(){
    fill(dp, dp+N, INF);
    int res = 0;
    for(int i = 0; i < n; i++){
        int loc = (int)(lower_bound(dp, dp+n, num[i]) - dp);
        dp[loc] = num[i];
        res = max(res, loc + 1);
    }
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    len = get_LIS();

    fill(dp, dp+N, INF);
    for(int i = 0; i < n; i++){
        int loc = (int)(lower_bound(dp, dp+n, num[i]) - dp);
        dp[loc] = num[i];
        pl[i] = loc + 1;
    }
    fill(dp, dp+N, INF);
    for(int i = 0; i < n; i++) num[i] = N - num[i];
    for(int i = n-1; i >= 0; i--){
        int loc = (int)(lower_bound(dp, dp+n, num[i]) - dp);
        dp[loc] = num[i];
        pr[i] = loc + 1;
    }
    for(int i = 0; i < n; i++){
        if(ok(i)){
            cnt[pl[i]] ++;
        }
    }
    for(int i = 0; i < n; i++){
        if(!ok(i)) printf("1");
        else if(cnt[pl[i]] > 1) printf("2");
        else printf("3");
    }
}