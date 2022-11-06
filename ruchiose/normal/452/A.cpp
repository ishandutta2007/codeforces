// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const char* poke[8] = 
{"vaporeon", "jolteon", "flareon", "espeon",
 "umbreon", "leafeon", "glaceon", "sylveon"};
 
const int len[8] = {8, 7, 7, 6, 7, 7, 7, 7};

int N;
char ch[8];

int main()
{
    scanf("%d%s", &N, ch);
    int i, j;
    fortodo(i, 0, 7)
        if (len[i] == N)
            {
                fortodo(j, 0, N - 1)
                    if ((poke[i][j] != ch[j]) && (ch[j] != '.'))
                        break;
                if (j == N)
                    {
                        puts(poke[i]);
                        return 0;
                    }
            }
    puts(poke[0]); // default
}