#include<bits/stdc++.h>
using namespace std;
int n, k, A[200000];
set < int > S;
map < int , int > M;
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i > k)
        {
            M[A[i - k]] --;
            if (M[A[i - k]] == 0)
            {
                S.erase(A[i - k]);
            }
            else if (M[A[i - k]] == 1)
            {
                S.insert(A[i - k]);
            }
        }
        if (M.count(A[i]) == 0 || M[A[i]] == 0)
        {
            M[A[i]] = 0;
            S.insert(A[i]);
        }
        else if (M[A[i]] == 1)
        {
            S.erase(A[i]);
        }
        M[A[i]] ++;
        if (i < k)
            continue;
        if (S.size() == 0)
        {
            printf("Nothing\n");
            continue;
        }
        printf("%d\n", *(S.rbegin()));
    }
    return (0);
}