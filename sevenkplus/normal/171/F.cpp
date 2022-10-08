#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10000010
int p[N],L;bool a[N];
int b[100],l;
int rev(int x)
{
    l=0;
    while(x)b[l++]=x%10,x/=10;
    for(int i=0;i<l;i++)(x*=10)+=b[i];
    return x;
}
int main()
{
    for(int i=2;i<=10000000;i++)
    {
        if(!a[i])p[L++]=i;
        for(int j=0;j<L;j++)
            if(p[j]*i<=10000000)
            {
                a[i*p[j]]=1;
                if(i%p[j]==0)break;
            }else break;
    }
    int n,S=0;scanf("%d",&n);
    for(int i=10;i<=10000000;i++)if(!a[i])
    {
        int w=rev(i);
        if(!a[i]&&!a[w]&&i!=w)
        {
            S++;
            if(S==n){printf("%d\n",i);return 0;}
        }
    }
    return 0;
}