#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) a[i]=0;
        int dif=0,maxi=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if(!a[x]) dif++;
            a[x]++;
            maxi=max(maxi,a[x]);
        }
        if(maxi==dif) printf("%d\n",maxi-1);
        else printf("%d\n",min(maxi,dif));
    }
    return 0;
}