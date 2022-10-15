#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=INF;
        for(int i=2;i*i<=n;i++) 
        {
            if(n%i==0)
            {
                ans=min(ans,n-n/i);
            }
        }
        ans=min(ans,n-1);
        printf("%d %d\n",n-ans,ans);
    }
}