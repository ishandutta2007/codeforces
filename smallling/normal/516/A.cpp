#include<cstdio>
#include<algorithm>

using namespace std;

int n,tot,a[1010];
char ch;

int main()
{
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%c",&ch);
        if(ch<='1')continue;
        if(ch=='2')a[++tot]=ch-'0';
        if(ch=='3')a[++tot]=ch-'0';
        if(ch=='4')a[++tot]=3,a[++tot]=2,a[++tot]=2;
        if(ch=='5')a[++tot]=5;
        if(ch=='6')a[++tot]=5,a[++tot]=3;
        if(ch=='7')a[++tot]=7;
        if(ch=='8')a[++tot]=7,a[++tot]=2,a[++tot]=2,a[++tot]=2;
        if(ch=='9')a[++tot]=7,a[++tot]=2,a[++tot]=3,a[++tot]=3;
    }
    sort(a+1,a+1+tot);
    for(int i=tot;i;i--)putchar(a[i]+'0');
}