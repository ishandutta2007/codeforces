// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, k, A[N], FP[N];
vector < int > P[N];
vector < pair < int , int > > V[N], R[N];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 2; i < N; i ++)
        if (!FP[i])
            for (int j = i; j < N; j += i)
                FP[j] = i;
    for (int i = 2; i < N; i ++)
    {
        P[i] = P[i / FP[i]];
        P[i].push_back(FP[i]);
        sort(P[i].begin(), P[i].end());
    }
    long long tot = 0;
    map < vector < pair < int , int > > , int > MP;
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &A[i]);
        for (int j = 0; j < (int)P[A[i]].size(); )
        {
            int r = j;
            while (r < (int)P[A[i]].size() && P[A[i]][j] == P[A[i]][r])
                r ++;
            V[i].push_back({P[A[i]][j], (r - j) % k});
            j = r;
        }
        sort(V[i].begin(), V[i].end());
        for (int j = 0; j < (int)V[i].size(); j ++)
            if (V[i][j].second % k == 0)
                swap(V[i][j], V[i].back()), V[i].pop_back(), j --;
        sort(V[i].begin(), V[i].end());
        for (int j = 0; j < (int)V[i].size(); j ++)
            R[i].push_back({V[i][j].first, k - V[i][j].second});
        tot += MP[V[i]]; MP[R[i]] ++;
    }
    printf("%lld\n", tot);
    return 0;
}