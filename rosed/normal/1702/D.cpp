#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
const int N=5e5+10,mod=1e9+7;
int n,m;
int a[N];
char s[N];
typedef pair<int,int> pr;
priority_queue<pr> q;

bool vis[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int qwq;cin>>qwq;
    while(qwq--)
    {
        while(!q.empty()) q.pop();
        cin>>(s+1);
        n=strlen(s+1);
        cin>>m;
        int sum=0;
        for(int i=1;i<=n;++i)
        {
            vis[i]=1;
            sum+=(s[i]-'a'+1);
            q.push(pr(s[i]-'a'+1,i));
        }
        while(sum>m)
        {
            auto now=q.top();
            q.pop();
            sum-=now.first;
            vis[now.second]=0;
        }
        for(int i=1;i<=n;++i) if(vis[i]) cout<<s[i];
        cout<<'\n';
    }
    return 0;
}