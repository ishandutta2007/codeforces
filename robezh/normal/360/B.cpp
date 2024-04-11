#include <bits/stdc++.h>
using namespace std;

const int N = 2050, INF = (int)1e9;

typedef long long ll;
int n,k;
int num[N];
int dp[N];

bool check(ll dif){
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(1LL * abs(num[i] - num[j]) <= 1LL * (i - j) * dif){
                dp[i] = min(dp[i], dp[j] + (i - j - 1));
            }
        }
        dp[i] = min(dp[i], i);
    }
    int res = INF;
    for(int i = 0; i < n; i++) res = min(res, dp[i] + (n - 1 - i));
    return res <= k;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> num[i];
    ll l = -1, r = 2 * INF, mid;
    while(l + 1 < r){
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}