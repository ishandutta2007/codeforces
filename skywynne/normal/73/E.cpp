#include<bits/stdc++.h>
using namespace std;
const int N = 2000006;
int n, x, cnt;
bool P[N], M[N];
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 0, a; i < n; i++)
    {
        scanf("%d", &a);
        if (a < N)
            M[a] = 1;
    }
    if (x <= 2)
        return !printf("0");
    if (M[1])
        return !printf("1");
    if (x >= N)
        return !printf("-1");
    for (int i = 2; i < x; i++)
        if (!P[i])
        {
            if (!M[i])
                return !printf("-1");
            for (int j = i + i; j < N; j += i)
                    P[j] = 1;
            cnt ++;
        }
    return !printf("%d", cnt);
}