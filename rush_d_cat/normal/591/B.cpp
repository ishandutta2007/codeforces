#include<iostream>
#include<stdio.h>
#include<cstdio>
using namespace std;
char s[200000 + 10];
int res[200];
int main()
{
    int n, m;
    char a, b;
    for(int i = 1; i < 200; i++) {
        res[i] = i;
    }
    cin >> n >> m >> s;

    for(int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        for(int j = 1; j < 200; j++)
        {
            if(res[j] == (int)a) {
                res[j] = (int)b;
            } else
            if(res[j] == (int)b) {
                res[j] = (int)a;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%c",(char)res[(int)s[i]]);
    }
    return 0;
}