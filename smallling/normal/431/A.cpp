#include<cstdio>

using namespace std;

int a[5],ans;
char ch;

int main()
{
    for(int i=0;i++<4;)
        scanf("%d",&a[i]);
    ch=getchar();
    while(ch<'1'||ch>'4')ch=getchar();
    while(ch!='\n')
    {
        ans+=a[ch-'0'];
        ch=getchar();
    }
    printf("%d",ans);
}