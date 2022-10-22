#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int N,M;
int a[2010],b[2010];
int x;
int vb[2010],va[2010];

int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)scanf("%d",&a[i]),a[i]+=a[i-1];
    for(int i=1;i<=M;i++)scanf("%d",&b[i]),b[i]+=b[i-1];
    for (int i=1;i<=max(N,M);i++)va[i] = vb[i] = 2e9;
    for (int i=1;i<=M;i++)
        for (int j=i;j<=M;j++)
            vb[j-i+1] = min(vb[j-i+1],b[j]-b[i-1]);
    for (int i=1;i<=N;i++)
        for (int j=i;j<=N;j++)
            va[j-i+1] = min(va[j-i+1],a[j]-a[i-1]);
    scanf("%d",&x);
    int now = M,ans = 0;
    for (int i=1;i<=N;i++)
    {
        while(1LL * va[i] * vb[now] > x) now--;
        ans = max(ans, i * now);
    }
    printf("%d\n",ans);
}