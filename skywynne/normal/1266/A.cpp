// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 400 + 10;
int n, A[N];
char S[N];
int main()
{
    int q;
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%s", &S);
        n = strlen(S);
        int zero = 0, sm = 0, even = 0;
        for (int i = 0; i < n; i ++)
            zero += (S[i] == '0'),
            sm += (S[i] - '0'),
            even += ((S[i] - '0') % 2 == 0);
        if (zero == 0 || sm % 3 != 0 || even == 1)
            printf("cyan\n");
        else
            printf("red\n");
        memset(S, 0, sizeof(S));
    }
    return 0;
}