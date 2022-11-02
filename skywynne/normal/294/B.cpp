#include<bits/stdc++.h>
using namespace std;
int n, r, t, Mn = 1e9, PS[110], PF[110];
vector < int > F, S;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &r, &t);
        if (r == 1)
        {
            F.push_back(t);
        }
        else
        {
            S.push_back(t);
        }
    }
    sort(F.begin(), F.end());
    reverse(F.begin(), F.end());
    sort(S.begin(), S.end());
    reverse(S.begin(), S.end());
    for (int i = 0; i < F.size() ; i ++)
    {
        PF[i + 1] = PF[i] + F[i];
    }
    for (int i = 0; i < S.size() ; i ++)
    {
        PS[i + 1] = PS[i] + S[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j > S.size() || i - j > F.size())
            {
                continue;
            }
            if (PF[F.size()] - PF[i - j] + PS[S.size()] - PS[j] <= i + j)
            {
                Mn = min(Mn, i + j);
            }
        }
    }
    printf("%d", Mn);
    return (0);
}