#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
 
using namespace std;
const int N = 5005;
const int K = 8;
 
int n, k, p[N], pos[N], dp[N][1 << K], t[N];
 
int sum(int r)
{
    int ans = 0;
 
    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r];
 
    return ans;
}
 
void inc(int i, int d)
{
    for(; i < N; i |= i + 1)
        t[i] += d;
}
 
int inv(int mn, int mask, int x)
{
    int ans = 0;
 
    for(int i = 0; i < k; i++)
        if((mask & (1 << i)) && pos[x] < pos[mn + 1 + i])
            ans++;
 
//    for(int i = 0; i < mn; i++)
//        if(pos[x] < pos[i])
//            ans++;
 
    ans += sum(N - 1) - sum(pos[x]);
 
    return ans;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> k;
 
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
 
        pos[p[i]] = i;
    }
 
    for(int mn = 0; mn <= n; mn++)
        for(int mask = 0; mask < (1 << k); mask++)
            dp[mn][mask] = 1e9;
 
    dp[0][0] = 0;
 
    for(int mn = 0; mn < n; mn++)
    {
        for(int mask = 0; mask < (1 << min(k, n - mn - 1)); mask++)
        {
            for(int i = 0; i < min(k, n - mn - 1); i++)
                if((mask & (1 << i)) == 0)
                    dp[mn][mask + (1 << i)] = min(dp[mn][mask + (1 << i)], dp[mn][mask] + inv(mn, mask, mn + 1 + i));
 
            int mn2 = mn, mask2 = mask;
 
            mn2++;
 
            while(mask2 % 2)
            {
                mn2++;
                mask2 /= 2;
            }
 
            mask2 /= 2;
 
            dp[mn2][mask2] = min(dp[mn2][mask2], dp[mn][mask] + inv(mn, mask, mn));
        }
 
        inc(pos[mn], 1);
    }
 
 
    cout << dp[n][0];
}