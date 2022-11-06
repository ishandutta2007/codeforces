#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N;

int main()
{
    scanf("%d", &N);
    if (N <= 3)
        {
            if (N == 1) printf("1\n");
            if (N == 2) printf("2\n");
            if (N == 3) printf("6\n");
        }
    else
        if (N & 1)
            cout << (i64)N * (N - 1) * (N - 2) << endl;
        else
            if (N % 3 == 0)
                cout << (i64)(N - 1) * (N - 2) * (N - 3) << endl;
            else
                cout << (i64)N * (N - 1) * (N - 3) << endl;
}