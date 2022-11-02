// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 209;
int n, m, Z[N * 10];
long long k, dp[N];
string S[N], F[N];
inline int ZFunc(string A, string B, string C)
{
    int l = 0, r = 0;
    string T = A + "#" + B + C;
    Z[0] = (int)T.size();
    for (int i = 1; i < (int)T.size(); i ++)
    {
        if (Z[i - l] < r - i)
            {Z[i] = Z[i - l]; continue;}
        l = i; r = max(r, i);
        while (r < (int)T.size() && T[r] == T[r - l])
            r ++;
        Z[i] = r - l;
    }
    int c = 0;
    for (int i = (int)A.size() + 1; i < (int)A.size() + 1 + (int)B.size(); i ++)
        if (Z[i] == (int)A.size() && i + Z[i] > (int)A.size() + (int)B.size() + 1)
            c ++;
    return (c);
}
inline long long Count(string R)
{
    dp[0] = R == "0";
    dp[1] = R == "1";
    for (int i = 2; i <= n; i ++)
        dp[i] = min(dp[i - 1] + dp[i - 2] + ZFunc(R, F[i - 2], S[i - 1]), k + 1);
    return (dp[n]);
}
int main()
{
    scanf("%d%lld%d", &n, &k, &m);
    S[0] = F[0] = "0";
    S[1] = F[1] = "1";
    for (int i = 2; i < N; i ++)
    {
        if (S[i - 2].size() < N)
            S[i] = F[i] = S[i - 2] + S[i - 1];
        else
            S[i] = S[i - 2], F[i] = F[i - 1];
    }
    string R;
    for (int i = 1; i <= m && k; i ++)
    {
        long long c = Count(R + "0");
        if (c >= k)
            {R += "0"; continue;}
        k -= c;
        R += "1";
        bool suf = 1;
        for (int j = 0; j < (int)R.size(); j ++)
            if (R[j] != F[n][(int)F[n].size() - (int)R.size() + j])
                suf = 0;
        if (suf) k --;
    }
    printf("%s\n", R.c_str());
    return 0;
}