#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,l,cnt[31];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&l);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            int x; scanf("%d",&x);
            for(int j=0;j<l;j++) if(x&(1<<j)) cnt[j]++;
        }
        int now=0;
        for(int j=0;j<l;j++)
        {
            if(cnt[j]>n-cnt[j]) now+=(1<<j);
        }
        printf("%d\n",now);
    }
    return 0;
}