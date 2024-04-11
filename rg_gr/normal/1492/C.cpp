#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
inline int read()
{
    int num=0;char c=getchar();
    while(c<48||c>57)c=getchar();
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num;
}
inline int max(int a,int b)
{
    return a>b?a:b;
}
char aa[200005],ba[200005];
int a[200005],b[200005];
int c[27][200005];
int t[27];
int pos[200005];
bool cmp(int a,int b)
{
    return a>b;
}
signed main()
{
//  a[0]=2,a[1]=2;
//printf("%d\n",std::lower_bound(a,a+2,2)-a);
    int n=read(),m=read(),cur=n+1;
    scanf("%s\n%s",aa,ba);
    for(int i=1;i<=n;i++)a[i]=aa[i-1]-97;
    for(int i=1;i<=m;i++)b[i]=ba[i-1]-97;
    for(int i=1;i<=n;i++)c[a[i]][t[a[i]]]=i,t[a[i]]++;
    for(int i=m;i>=1;i--)
    {
        int x=std::lower_bound(c[b[i]],c[b[i]]+t[b[i]],cur)-c[b[i]]-1;
      cur=pos[i]=c[b[i]][x];
        //for(int i=1;i<=m;i++)printf("%d ",pos[i]);puts("");
    }
    cur=0;int ans=0;
    for(int i=1;i<m;i++)
    {
        int x=std::upper_bound(c[b[i]],c[b[i]]+t[b[i]],cur)-c[b[i]];
        pos[i]=c[b[i]][x];
        ans=max(ans,pos[i+1]-pos[i]);
        cur=c[b[i]][x];
    }
    printf("%d\n",ans);
}