#include<cstdio>

using namespace std;

int a,b,ans;

int main()
{
    scanf("%d%d",&a,&b);
    a-=b;
    if(a==0)return puts("infinity"),0;
    for(int i=1;i*i<=a;i++)
        if(a%i==0)
        {
            if(i>b)ans++;
            if((a/i)>b)
            {
                ans++;
                if(i==a/i)ans--;
            }
        }
    printf("%d",ans);
}