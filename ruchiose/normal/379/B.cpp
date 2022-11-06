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

int N, A[301], i, j;

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &A[i]);
    fortodo(i, 1, A[1]) printf("PRL");
    fortodo(i, 2, N)
        {
            printf("R");
            fortodo(j, 1, A[i]) printf("PLR");
        } 
    printf("\n");
    return 0;
}