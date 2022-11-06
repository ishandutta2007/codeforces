#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, i;
double Pi;
d64 Bonus, Score;

int main()
{
    Score = 0; Bonus = 1;
    scanf("%d", &N);
    fortodo(i, 1, N)
        {
            scanf("%lf", &Pi);
            Score += Pi * Bonus;
            Bonus = Pi * (Bonus + 2) + (1 - Pi);
        }
    printf("%.10f\n", double(Score));
}