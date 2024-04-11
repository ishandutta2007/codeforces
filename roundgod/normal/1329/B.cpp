#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,d,m;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&d,&m);
        int sum=1;
        int ans=0;
        for(int i=0;i<30;i++)
        {
            if((1<<i)>d) break;
            int res=min(d-(1<<i)+1,(1<<i));
            ans=(1LL*sum*res)%m;
            sum=(sum+ans)%m;
        }
        sum=sum-1;
        if(sum<0) sum+=m;
        printf("%d\n",sum);
    }
    return 0;
}