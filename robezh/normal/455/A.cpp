#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = (int)1e5 + 500;

int n, a;
ll dp[MAXN];
int cnt[MAXN];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){cin >> a; cnt[a] ++;}
    dp[0] = 0;
    dp[1] = cnt[1];
    for(int i = 2; i <= (int)1e5 + 2; i++){
        dp[i] = max(dp[i-1], dp[i-2] + 1LL * cnt[i] * i);
    }
    cout << dp[(int)1e5 + 2];
}