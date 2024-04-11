#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 200020
using namespace std;

int n,l,r,mid,a[maxn],b[maxn],m,k;
char s[maxn];

int dis(int x,int y,int z)
{
    return min(abs(a[z]-b[x]),abs(a[z]-b[y]))+b[y]-b[x];
}

bool ck(int x)
{
    int j=0,p=0;
    while (j<k&&p<m){
        int j2=j;
        while (j2<k&&dis(j,j2,p)<=x) j2++;
        j=j2;p++;
    }
    return (j==k);
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    m=k=0;
    for (int i=0;i<n;i++){
        if (s[i]=='P') a[m++]=i;
        if (s[i]=='*') b[k++]=i;
    }
    l=0;r=2*n;
    while (r-l>1){
        mid=(l+r)/2;
        if (ck(mid)) r=mid; else l=mid;
    }
    if (ck(l)) printf("%d\n",l); else printf("%d\n",r);
    return 0;
}