#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200005
using namespace std;
int n,a[N],num[N],b[N],ans,tot=1;
bool used[N],vis[N];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
    scanf("%d",a+i),
    used[a[i]]=1,num[a[i]]++;
    for(int i=1;i<=n;i++)
    if(num[i])ans+=num[i]-1;
    for(int i=0;i<n;i++)
    {
        if(num[a[i]]>1)
        {
            if(vis[a[i]])
            {
                while(tot<n&&used[tot])tot++;
                b[i]=tot++;
            }
            else
            {
                while(tot<a[i]&&used[tot])tot++;
                if(tot>=a[i]){b[i]=a[i],vis[a[i]]=1;continue;}
                else b[i]=tot++,num[a[i]]--;
            }
        }
        else b[i]=a[i];
    }
    printf("%d\n%d",ans,b[0]);
    for(int i=1;i<n;i++)printf(" %d",b[i]);
}
/*
6
6 6 6 1 1 1
*/