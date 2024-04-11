#include<bits/stdc++.h>
using namespace std;
int n, q, A[100010];
vector < int > V;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0 && n / i > 2)
        {
            V.push_back(i);
        }
    }
    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 1; j <= V[i]; j++)
        {
            q = 1;
            for (int k = 0; j + k <= n; k += V[i])
            {
                if (A[j + k] == 0)
                {
                    q = 0;
                    break;
                }
            }
            if (q == 1)
            {
                printf("YES");
                return (0);
            }
        }
    }
    printf("NO");
    return (0);
}