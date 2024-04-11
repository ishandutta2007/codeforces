#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,ans,a[1000010],b[1000010],f[1000010];

void read(int &x)
{
    x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)read(a[i]),b[a[i]]=i,f[i]=1;
    for(int i=1;i<=n;i++)
        for(int j=a[i]+a[i];j<=a[n];j+=a[i])
        {
            if(!b[j])continue;
            f[b[j]]=max(f[b[j]],f[i]+1);
        }
    for(int i=1;i<=n;i++)ans=max(ans,f[i]);
    printf("%d",ans);
}