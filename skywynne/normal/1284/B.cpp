// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, m, q, cnt, M[N];
vector < int > L, R, A[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int len, a;
        scanf("%d", &len);
        for (; len; len --)
            scanf("%d", &a), A[i].push_back(a);
        for (int j = 1; j < (int)A[i].size(); j ++)
            if (A[i][j] > A[i][j - 1])
                M[i] = 1;
        if (!M[i])
        {
            L.push_back(A[i].back());
            R.push_back(A[i][0]);
            cnt ++;
        }
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int r = 0;
    long long tot = 1LL * (n - cnt) * n + 1LL * cnt * (n - cnt);
    for (int i = 0; i < (int)L.size(); i ++)
    {
        while (r < (int)R.size() && R[r] <= L[i])
            r ++;
        tot += (int)R.size() - r;
    }
    printf("%lld\n", tot);
    return 0;
}