#include<cstdio>

using namespace std;

int x1,y1,x2,y2,a[101],o;
char ch;

int main()
{
    scanf("%c%d",&ch,&y1);
    x1=ch-'a'+1;
    getchar();
    scanf("%c%d",&ch,&y2);
    x2=ch-'a'+1;
    while(x1<x2&&y1<y2)a[++o]=1,x1++,y1++;
    while(x1>x2&&y1<y2)a[++o]=2,x1--,y1++;
    while(x1<x2&&y1>y2)a[++o]=3,x1++,y1--;
    while(x1>x2&&y1>y2)a[++o]=4,x1--,y1--;
    while(x1>x2)a[++o]=5,x1--;
    while(x1<x2)a[++o]=6,x1++;
    while(y1>y2)a[++o]=7,y1--;
    while(y1<y2)a[++o]=8,y1++;
    printf("%d\n",o);
    for(int i=1;i<=o;i++)
    {
        if(a[i]==1)puts("RU");
        if(a[i]==2)puts("LU");
        if(a[i]==3)puts("RD");
        if(a[i]==4)puts("LD");
        if(a[i]==5)puts("L");
        if(a[i]==6)puts("R");
        if(a[i]==7)puts("D");
        if(a[i]==8)puts("U");
    }
}