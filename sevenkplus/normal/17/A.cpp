#include<cstdio>
int a[1000],l;
bool pr(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}
int main()
{
    for(int i=2;i<1000;i++)
        if(pr(i))
            a[l++]=i;
    int n,k;
    scanf("%d%d",&n,&k);
    int s=0;
    for(int i=0;i+1<l;i++)
        s+=a[i]+a[i+1]+1<=n&&pr(a[i]+a[i+1]+1);
    puts(s>=k?"YES":"NO");          
    return 0;
}