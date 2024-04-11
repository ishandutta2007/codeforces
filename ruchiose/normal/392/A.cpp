#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

i64 N, Far;

int main()
{
    scanf("%I64d", &N);
    if (N == 0)
        {
            printf("1\n");
            return 0;
        }
    Far = (i64)sqrt(N * N / 2);
    if (Far * Far * 2 + Far * 2 + 1 <= N * N)
        cout << 8 * Far + 4 << endl;
    else
        cout << 8 * Far << endl;
}