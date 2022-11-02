#include<cstdio>
#include<cstring>

using namespace std;

char s[10001][1001],ch;
int l[10001],o,maxx,f;

int main()
{
    while(ch!=-1)
    {
        o++;
        ch=getchar();
        while(ch!='\n'&&ch!=-1)s[o][++l[o]]=ch,ch=getchar();
        if(l[o]>maxx)maxx=l[o];
    }
    o--;       
    for(int i=1;i<=maxx+2;i++)
        putchar('*');
    putchar('\n');
    for(int i=1;i<=o;i++)
    {
        putchar('*');
        int now=(maxx-l[i])/2+((maxx-l[i])%2&&f);
        if((maxx-l[i])%2)f^=1;
        for(int j=1;j<=now;j++)
            putchar(' ');
        for(int j=1;j<=l[i];j++)
            putchar(s[i][j]);
        for(int j=1;j<=maxx-l[i]-now;j++)
            putchar(' ');
        putchar('*');
        putchar('\n');
    }
    for(int i=1;i<=maxx+2;i++)
        putchar('*');
    putchar('\n');
}