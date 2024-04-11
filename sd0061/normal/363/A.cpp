#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define N 1005

int n ;
char s[N];



void work()
{
    cin >> n;
    sprintf(s , "%d" , n);
    int l = strlen(s) - 1;
    for (int i = l ; i >= 0 ; -- i)
    {
        if (s[i] == '0') puts("O-|-OOOO");
        if (s[i] == '1') puts("O-|O-OOO");
        if (s[i] == '2') puts("O-|OO-OO");
        if (s[i] == '3') puts("O-|OOO-O");
        if (s[i] == '4') puts("O-|OOOO-");
        if (s[i] == '5') puts("-O|-OOOO");
        if (s[i] == '6') puts("-O|O-OOO");
        if (s[i] == '7') puts("-O|OO-OO");
        if (s[i] == '8') puts("-O|OOO-O");
        if (s[i] == '9') puts("-O|OOOO-");
    }
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d%d",&n,&m,&k))
        work();
    return 0;
}