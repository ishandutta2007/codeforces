// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 74;
int q, n, A[N];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &A[i]);
    int Mn = INT_MAX;
    for (int l = 0; l < n; l ++)
    {
        map < int , int > C;
        for (int i = 0; i < n; i ++)
            C[A[i]] ++;
        int cnt = 0;
        for (auto X : C)
            if (X.second > 1)
                cnt ++;
        int r = l;
        while (cnt && r < n)
            C[A[r]] --, cnt -= (C[A[r]] == 1), r ++;
        if (cnt == 0)
            Mn = min(Mn, r - l);
    }
    printf("%d\n", Mn);
    return 0;
}