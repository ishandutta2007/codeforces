#include<bits/stdc++.h>
#define MAXN 6005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int cnt[4];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int id=0;
        if((x/2)&1) id+=2;
        if((y/2)&1) id++;
        cnt[id]++;
    }
    ll ans=0;
    for(int i=0;i<4;i++)
        for(int j=i;j<4;j++)
            for(int k=j;k<4;k++)
            {
                if(i!=j&&j!=k&&i!=k) continue; 
                if(i==j&&j==k) ans+=1LL*cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
                else if(i==j) ans+=1LL*cnt[i]*(cnt[i]-1)*cnt[k]/2;
                else if(i==k) ans+=1LL*cnt[i]*(cnt[i]-1)*cnt[j]/2;
                else if(j==k) ans+=1LL*cnt[j]*(cnt[j]-1)*cnt[i]/2;
            }
    printf("%lld\n",ans);
    return 0;
}