#include <iostream>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <stdio.h>
using namespace std;
typedef __int64 ll;
char s[100000 + 10];
int main()
{
    bool ok = false;
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int i = 1;
    while(s[i] == 'a') i++;
    if(i == len + 1){
        s[len] = 'z';
    }
    while(i <= len)
    {
        if(s[i] == 'a') break;
        s[i] = (char)((int)s[i] - 1);
        i ++;
    }
    for(i = 1; i <= len; i++) cout << s[i];
}


/*
int main()
{
    ll n, b, d, tot = 0, tmp, i, res = 0;
    cin >> n >> b >> d;
    for(i = 1; i <= n; i++)
    {
        cin >> tmp;
        if(tmp >= b) continue;
        else tot += b;
        res += (tot/d);
        if(tot >= d) tot = 0;
    }
    cout << res;
}
*/