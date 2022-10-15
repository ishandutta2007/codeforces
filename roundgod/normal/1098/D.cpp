#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
multiset<int> ms;
int q,x;
ll sum[30];
int cur[30];
string str;
int solve()
{
    int cnt=0;
    for(int i=0;i<=29;i++)
    {
        if(!cur[i]) continue;
        if(cur[i]>2*sum[i]) cnt++;
    }
    return cnt;
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        cin>>str; scanf("%d",&x);
        int t=0;
        while((1<<(t+1))<=x) t++;
        if(str[0]=='-')
        {
            ms.erase(ms.find(x));
            auto it=ms.lower_bound(1<<t);
            if(it==ms.end()||*it>=(1<<(t+1))) cur[t]=0; else cur[t]=*it;
            for(int i=t+1;i<=29;i++) sum[i]-=x;
        }
        else
        {
            ms.insert(x);
            if(cur[t]==0) cur[t]=x; else cur[t]=min(cur[t],x);
            for(int i=t+1;i<=29;i++)
                if(x<(1<<i)) sum[i]+=x;
        }
        printf("%d\n",(int)ms.size()-solve());
    }
    return 0;
}