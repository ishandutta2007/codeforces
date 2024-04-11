#include <bits/stdc++.h>
using namespace std;

const int N = 2050, INF = (int)1e9;
typedef pair<int, int> P;

int n;
P num[N];
int dp[N][N];
int vis[N], l[N], r[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i].first;
        num[i].second = i;
        if(num[i].first < 0) num[i].first = -num[i].first;
    }
    sort(num, num+n);
    int res = 0;
    for(int i = 0; i < n;){
        int nx = i;
        while(nx < n && num[nx].first == num[i].first) nx++;

        l[0] = vis[0];
        for(int j = 1; j < n; j++) l[j] = l[j-1] + vis[j];
        r[n-1] = vis[n-1];
        for(int j = n-2; j >= 0; j--) r[j] = r[j+1] + vis[j];

        for(int j = 0; j < nx - i; j++) fill(dp[j], dp[j] + nx - i + 1, INF);
        dp[0][0] = l[num[i].second]; dp[0][1] = r[num[i].second];
        for(int j = i + 1; j < nx; j++){
            dp[j - i][0] = dp[j - i - 1][0] + l[num[j].second];
            for(int t = 1; t <= nx - i; t++){
                dp[j - i][t] = min(dp[j - i - 1][t] + l[num[j].second], dp[j - i - 1][t-1] + r[num[j].second]);
            }
        }
        int cur = INF;
        for(int j = 0; j <= nx - i; j++) cur = min(cur, dp[nx-1-i][j]);
        res += cur;
        for(int j = i; j < nx; j++) vis[num[j].second] = 1;
        i = nx;
    }
    cout << res << endl;

}