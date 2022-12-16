#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
const int N=5e5+10,mod=1e9+7;
int n,m;
int a[N];
map<int,int> q1,q2;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int qwq;cin>>qwq;
    while(qwq--)
    {
        cin>>n>>m;
        q1.clear(),q2.clear();
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(q1.find(a[i])==q1.end()) q1[a[i]]=i;
            q2[a[i]]=i;
        }
        for(int i=1;i<=m;++i)
        {
            int x,y;
            cin>>x>>y;
            if(q1[x]==0||q1[y]==0||q1[x]>q2[y])
            {
                cout<<"NO\n";
            }
            else cout<<"YES\n";
        }
    }
    return 0;
}