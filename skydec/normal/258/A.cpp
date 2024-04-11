#include<stdio.h>
#include<cstring>
using namespace std;
bool flag=false;
char str[110000];
int main()
{
    long len=0;
    while(true)
    {
               char p=getchar();
               if(p!='0'&&p!='1')break;
               str[++len]=p;
               }
    for(long i=1;i<=len;i++)
    if((str[i]=='0'&&!flag)||(i==len&&!flag))
    flag=true;
    else putchar(str[i]);
    return 0;
}