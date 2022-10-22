#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int s[maxn], dp[maxn];
int main(){
    int T, n;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i= 1; i<=n; i++) cin >> s[i],  dp[i] = 1;
        for (int i = 1; i<=n; i++)
            for (int j = i+i; j<=n; j+=i)
                if (s[i] < s[j] &&  dp[i]+1 > dp[j]) dp[j] = dp[i] + 1;
        int ans = 0;
        for (int i = 1; i<=n; i++)
            if (dp[i] > ans) ans = dp[i];
        printf("%d\n", ans);
    }
    return 0;
}