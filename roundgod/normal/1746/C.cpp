#pragma GCC optimize(3)
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
        vector<P> v;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(i==0) v.push_back(P(0,1));
            else if(a[i]>=a[i-1]) v.push_back(P(0,i));
            else v.push_back(P(a[i-1]-a[i],i));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++) printf("%d ",v[i].S);
        printf("\n");
    }
    return 0;
}