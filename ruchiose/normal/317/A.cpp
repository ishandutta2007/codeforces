#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

i64 X, Y, M, A;

int main()
{
    cin >> X >> Y >> M;
    if (max(X, Y) >= M)
        {
            printf("0\n");
            return 0;
        }
    if ((X <= 0) && (Y <= 0))
        {
            printf("-1\n");
            return 0;
        }
    if (X > Y) swap(X, Y);
    A = max(0ll, (- X + Y - 1) / Y);
    X += A * Y;
    while (Y < M)
        {
            A++;
            swap(X, Y);
            Y += X;
        }
    cout << A << endl;
}