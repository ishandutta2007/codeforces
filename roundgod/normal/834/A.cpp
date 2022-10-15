#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int main()
{
    char a[3];
    int x,y,n;
    gets(a);
    scanf("%d",&n);
    n=n%4;
    if(a[0]=='^') x=0;
    if(a[0]=='<') x=1;
    if(a[0]=='v') x=2;
    if(a[0]=='>') x=3;
    if(a[2]=='^') y=0;
    if(a[2]=='<') y=1;
    if(a[2]=='v') y=2;
    if(a[2]=='>') y=3;
    if((x+n)%4==y&&(y+n)%4!=x)
    {
        printf("ccw\n");
        return 0;
    }
    else if((y+n)%4==x&&(x+n)%4!=y)
    {
        printf("cw\n");
        return 0;
    }
    else
    {
        printf("undefined\n");
        return 0;
    }
}