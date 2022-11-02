#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,tms,st[N],st_[N],lst[N],t,tt,k,i;
char S[N];
bool vis[N];
int main()
{
	scanf("%s",S+1);n=strlen(S+1);
	for(i=1;i<=n;i++)
    if(S[i]=='1')
    {
        if(!t)
        return puts("-1"),0;
        lst[i]=st[--t];
        st_[tt++]=i;
    }
    else
    {
        if(tt)lst[i]=st_[--tt];
        st[t++]=i;
    }
    if(tt)
    return puts("-1"),0;
    printf("%d\n",t);
    while(t--)
    {
        for(i=st[t],k=0;i;k++,i=lst[i]);
        printf("%d",k);tt=0;
        for(int i=st[t];i;i=lst[i])
        {
            st_[tt++]=i;
        }
        for(int i=tt-1;i>=0;i--)
        printf(" %d",st_[i]);puts("");
    }
}