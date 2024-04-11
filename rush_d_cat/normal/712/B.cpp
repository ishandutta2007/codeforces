#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef __int64 ll;
const ll M = 400000 + 100;
const ll inf  = 1e9 + 7;
char s[M];
int main()
{
    scanf("%s",s);
    int x=0,y=0;
    int len = strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]=='U')  y--;
        if(s[i]=='L')  x--;
        if(s[i]=='R') x++;
        if(s[i]=='D') y++;
    }
    if((x+y)%2==0)cout<<((abs(x)+abs(y))/2)<<endl;
    else cout<<-1<<endl;
}