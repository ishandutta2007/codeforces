#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

char p[101];
int N, i, c;

int main()
{
    scanf("%s", p);
    N = strlen(p);
    c = 0;
    fortodo(i, 0, N - 1)
        {
            if ((p[i] >= '0') && (p[i] <= '9')) c |= 1;
            if ((p[i] >= 'A') && (p[i] <= 'Z')) c |= 2;
            if ((p[i] >= 'a') && (p[i] <= 'z')) c |= 4;
        }
    if ((c == 7) && (N > 4))
        printf("Correct\n");
    else
        printf("Too weak\n");
}