// ItnoE
#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q, A[N], MX[N];
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i ++)
        scanf("%d", &A[i]), MX[A[i]] = max(MX[A[i]], i);
    int Mx = 0, lst = 0, Cnt = 0;
    for (int i = 0; i < n; i ++)
    {
        Mx = max(Mx, MX[A[i]]);
        if (Mx == i)
        {
            int MaxE = 0;
            map < int , int > MP;
            for (int j = lst; j <= i; j ++)
                MP[A[j]] ++;
            for (auto X : MP)
                MaxE = max(MaxE, X.second);
            Cnt += i - lst + 1 - MaxE;
            lst = i + 1;
        }
    }
    return !printf("%d\n", Cnt);
}