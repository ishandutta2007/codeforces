// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, q, A[N], C[N];
map < int , int > MP[N];
int main()
{
    scanf("%d", &n);
    long long SM = 0;
    for (int i = 1; i <= n; i ++)
        scanf("%d", &A[i]), SM += A[i];
    scanf("%d", &q);
    int cnt = 0;
    for (; q; q --)
    {
        int s, t, u;
        scanf("%d%d%d", &s, &t, &u);
        if (MP[s][t])
        {
            C[MP[s][t]] --;
            if (C[MP[s][t]] < A[MP[s][t]])
                cnt --;
        }
        MP[s][t] = u;
        if (MP[s][t])
        {
            C[MP[s][t]] ++;
            if (C[MP[s][t]] <= A[MP[s][t]])
                cnt ++;
        }
        printf("%lld\n", SM - cnt);
    }
    return 0;
}