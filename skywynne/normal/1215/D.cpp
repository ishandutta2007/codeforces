// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, Mn, Mx;
char A[N];
int main()
{
    scanf("%d%s", &n, A);
    for (int i = 0; i < n / 2; i ++)
    {
        if (A[i] != '?')
            Mn += A[i] - '0',
            Mx += A[i] - '0';
        else
            Mn += 0,
            Mx += 9;
    }
    for (int i = n / 2; i < n; i ++)
    {
        if (A[i] != '?')
            Mn -= A[i] - '0',
            Mx -= A[i] - '0';
        else
            Mn -= 9,
            Mx -= 0;
    }
    puts((Mn == - Mx) ? "Bicarp" : "Monocarp");
}