#include<bits/stdc++.h>
#define maxn 1000050

using namespace std;

int a[maxn],b[maxn],c[maxn],n,k,m,t;

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    a[n]=0; memset(c,-1,sizeof(c));
    m=0;b[m]=0;c[0]=0;t=0;
    for (int i=1;i<=n;i++) if (a[i]<a[b[m]]) b[++m]=i,c[i]=m;
    for (int i=1;i<=m;i++)
        if (b[i]-b[i-1]>2*k) {puts("NO");return 0;}
        else if (b[i]-b[i-1]>k)
        {
            if (t) {puts("NO");return 0;} else t=i;
        }
    if (!t||t<m&&b[t+1]-b[t-1]<=2*k) {puts("YES");return 0;}
    for (int i=b[t]+1;i<n;i++)
        if (c[i]==-1||b[c[i]+1]-b[c[i]-1]<=k){
            if (a[i]<a[b[t-1]]&&a[i]>a[b[t]]) {puts("YES");return 0;}
        }
    puts("NO");return 0;
}