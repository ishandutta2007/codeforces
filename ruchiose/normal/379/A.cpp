// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
#define mp make_pair
using namespace std;

int A, B;
int Burnt, Unrecycled, Available;

int main()
{
    scanf("%d%d", &A, &B);
    Burnt = Unrecycled = 0;
    Available = A;
    while (Available)
        {
            Burnt += Available;
            Unrecycled += Available;
            Available = Unrecycled / B;
            Unrecycled %= B;
        }
    printf("%d\n", Burnt);
    return 0;
}