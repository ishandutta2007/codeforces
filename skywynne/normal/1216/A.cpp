// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, c;
char A[N];
int main()
{
    scanf("%d%s", &n, A);
    for (int i = 0; i < n; i += 2)
        if (A[i] == A[i + 1])
            A[i + 1] = 'a' + 'b' - A[i], c ++;
    return !printf("%d\n%s\n", c, A);
}