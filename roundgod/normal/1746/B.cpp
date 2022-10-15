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
deque<int> pos0,pos1;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        pos0.clear(); pos1.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==0) pos0.push_back(i); else pos1.push_back(i);
        }
        int ans=0;
        while(pos0.size()&&pos1.size()&&pos0.back()>pos1.front())
        {
            ans++;
            pos0.pop_back(); pos1.pop_front();
        }
        printf("%d\n",ans);
    }
    return 0;
}