#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define MAXK 25
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,c[MAXN][MAXK];
ll p3[MAXK];
ll res[MAXN][MAXN];
map<ll,int> cnt;
int main()
{
    p3[0]=1;
    for(int i=1;i<=20;i++) p3[i]=3LL*p3[i-1];
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            scanf("%d",&c[i][j]);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int pos=0;pos<k;pos++)
            {
                int x=(c[i][pos]+c[j][pos])%3;
                res[i][j]+=p3[pos]*x;
            }
            //printf("i=%d j=%d res=%lld\n",i,j,res[i][j]);
            cnt[res[i][j]]++;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll tmp=0;
        for(int pos=0;pos<k;pos++) tmp+=((3-c[i][pos])%3)*p3[pos];
        int c=cnt[tmp];
        for(int j=0;j<i;j++) if(res[j][i]==tmp) c--;
        for(int j=i+1;j<n;j++) if(res[i][j]==tmp) c--;
        //printf("i=%d tmp=%lld c=%d\n",i,tmp,c);
        ans+=1LL*c*(c-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}