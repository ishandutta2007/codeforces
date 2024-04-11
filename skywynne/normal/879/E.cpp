#include<bits/stdc++.h>
using namespace std;
const int K = 11;
int n, k, A[K];
struct SCC
{
    int n, Mn[K], Mx[K];
    SCC ()
    {
        n = 1;
        for (int i = 0; i < k; i++)
            Mn[i] = Mx[i] = A[i];
    }
    void operator += (const SCC &X)
    {
        n += X.n;
        for (int i = 0; i < k; i++)
            Mn[i] = min(Mn[i], X.Mn[i]), Mx[i] = max(Mx[i], X.Mx[i]);
    }
    bool operator < (const SCC &X) const
    {
        for (int i = 0; i < k; i++)
            if (Mx[i] > X.Mn[i])
                return (0);
        return (1);
    }
};
int main()
{
    scanf("%d%d", &n, &k);
    set < SCC > S;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
            scanf("%d", &A[j]);
        SCC C;
        auto lb = S.lower_bound(C), up = S.upper_bound(C);
        for (; lb != up; lb = S.erase(lb))
            C += *lb;
        S.insert(C);
        printf("%d\n", (*S.rbegin()).n);
    }
    return (0);
}