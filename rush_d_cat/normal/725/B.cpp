#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 200000+10;
typedef long long ll;
char s[MAXN];
int main()
{
    scanf("%s", s + 1);
    int len = strlen(s+1), i, j;
    ll val = 0;
    ll num = 0;
    for(i = 1; i <= len; i++)
    {
        if(s[i]>='0' && s[i] <= '9')
        {
            val = val*10 + s[i] - '0';
        }
    }
    num += ((val-1)/4)*16;
    if(s[len]=='f') num+=1;
    if(s[len]=='e') num+=2;
    if(s[len]=='d') num+=3;
    if(s[len]=='a') num+=4;
    if(s[len]=='b') num+=5;
    if(s[len]=='c') num+=6;
    if(val%4==0||val%4==2)
    {
        num+=7;
    }
    cout<<num<<endl;
}