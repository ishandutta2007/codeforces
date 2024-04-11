#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=3;i<=n;i+=2)
        {
            if((1LL*i*i-1)/2<=n-1) ans++;
            else break;
        }
        printf("%d\n",ans);
    }
}