// ItnoE
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, C = 0;
    scanf("%d", &n);
    vector < int > A(n), M(n, 0);
    for (int i = 0; i < n; i ++)
        scanf("%d", &A[i]);
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i ++)
        if (!M[i])
        {
            C ++;
            for (int j = i; j < n; j ++)
                if (A[j] % A[i] == 0)
                    M[j] = 1;
        }
    return !printf("%d\n", C);
}