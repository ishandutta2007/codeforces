#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,b[MAXN];
ll ans,a[MAXN];
vector<int> G[MAXN];
int deg[MAXN];
vector<int> v1,v2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]!=-1) deg[b[i]]++;
    }
    queue<int> que;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==0) que.push(i);
    }
    ll ans=0;
    while(que.size())
    {
        int i=que.front(); que.pop();
        if(b[i]==-1)
        {
            ans+=a[i];
            v1.push_back(i);
        }
        else
        {
            if(a[i]>=0)
            {
                ans+=a[i];
                a[b[i]]+=a[i];
                v1.push_back(i);
            }
            else
            {
                ans+=a[i];
                v2.push_back(i);
            }
            deg[b[i]]--;
            if(deg[b[i]]==0) que.push(b[i]);
        }
    }
    reverse(v2.begin(),v2.end());
    for(auto x:v2) v1.push_back(x);
    printf("%lld\n",ans);
    for(auto x:v1) printf("%d ",x);
    puts("");
}