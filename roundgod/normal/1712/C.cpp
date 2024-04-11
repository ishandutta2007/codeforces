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
vector<int> pos[MAXN];
int bit[2*MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++) pos[i].clear(),bit[i]=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            pos[a[i]].push_back(i);
        }
        set<int> bad;
        int mini=INF;
        for(int i=n;i>=1;i--)
        {
            if(pos[i].size())
            {
                if(sum(n)-sum(pos[i][0]-1)+(int)pos[i].size()==n-pos[i][0]+1)
                {
                    for(auto x:pos[i]) add(x,1);
                }
                else ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}