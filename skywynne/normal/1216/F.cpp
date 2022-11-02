// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 400005;
int n, k;
long long dp[N];
char A[N];
vector < long long > V[N];
multiset < long long > S;
int main()
{
    scanf("%d%d%s", &n, &k, A + 1);
    dp[0] = 0;
    deque < int > D;
    D.push_back(0);
    for (int i = 1; i <= n; i ++)
    {
        while (D.front() < i - k - 1)
            D.pop_front();
        if (A[i] == '1')
            V[min(i + k, n)].push_back(dp[D.front()] + i), S.insert(dp[D.front()] + i);
        dp[i] = dp[i - 1] + i;
        if (S.size())
            dp[i] = min(dp[i], * S.begin());
        for (int a : V[i])
            S.erase(S.lower_bound(a));
        while (D.size() && dp[i] < dp[D.back()])
            D.pop_back();
        D.push_back(i);
    }
    return !printf("%lld\n", dp[n]);
}