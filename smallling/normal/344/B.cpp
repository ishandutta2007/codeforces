#include<cstdio>

using namespace std;

int a,b,c,a1,b1,c1;

int main()
{
    scanf("%d%d%d",&a,&b,&c);
    a1=a+b-c;
    b1=b+c-a;
    c1=c+a-b;
    if(a1<0||b1<0||c1<0||a1%2||b1%2||c1%2)puts("Impossible");
    else printf("%d %d %d",a1/2,b1/2,c1/2);
}