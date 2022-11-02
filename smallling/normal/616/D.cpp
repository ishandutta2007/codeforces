#include<cstdio>

using namespace std;

int n,k,K,cnt[1000010],L,R,Ans,a[1000010];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=1,r=1;
    cnt[a[1]]++;
    K=1;
    while(r<=n)
    {
        while(l<=r&&K>k)cnt[a[l]]--,K-=(cnt[a[l]]==0),l++;
        if(r-l+1>Ans)Ans=r-l+1,R=r,L=l;
        r++;
        cnt[a[r]]++;
        K+=(cnt[a[r]]==1);
    }
    printf("%d %d\n",L,R);
}