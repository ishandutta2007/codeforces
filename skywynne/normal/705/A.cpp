#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e6 + 10;
int n, r, t;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            printf("I hate ");
        }
        else
            printf("I love ");
        if (i != n - 1)
            printf("that ");
    }
    printf("it");
    return (0);
}