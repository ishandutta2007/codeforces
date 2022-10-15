#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,b,p,f,h,c;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
        int ans=0;
        for(int i=0;2*i<=b&&i<=p;i++)
        {
            int j=min((b-2*i)/2,f);
            ans=max(ans,h*i+j*c);
        }
        printf("%d\n",ans);
    }
    return 0;
}