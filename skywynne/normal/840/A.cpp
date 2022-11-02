#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, NX = 1e9 + 7;
int n, r, t, p, c, T[N];
pair < int , int > A[N], B[N];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i].x), A[i].y = i;
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i].x), B[i].y = i;
    sort(A, A + n);
    sort(B, B + n);
    reverse(A, A + n);
    for (int i = 0; i < n; i++)
        T[B[i].y] = A[i].x;
    for (int i = 0; i < n; i++)
        printf("%d ", T[i]);
    return (0);
}