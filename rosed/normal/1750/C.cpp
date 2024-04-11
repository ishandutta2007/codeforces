#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-9)
void solve()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    s="#"+s;
    t="#"+t;
    vector<int> a(n+1),b(n+1);
    int pre=0;
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        a[i]=s[i]-'0',b[i]=t[i]-'0';
        sum+=(a[i]^b[i]);
    }
    if(sum!=n&&sum!=0)
    {
        cout<<"NO\n";return;
    }
    typedef array<int,2> pr;
    multiset<pr> q;
    if(sum==n)
    {
        for(int i=1;i<=n;++i) a[i]^=1;
        q.insert(pr{1,n});
    }
    int tot=0,pos=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i])
        {
            q.insert(pr{i,i});
            if(!pos) pos=i;
            tot^=1;
        }
    }
    if(tot&1)
    {
        if(pos==n)
        {
            q.erase(pr{n,n});
            q.insert(pr{n-1,n});
            q.insert(pr{n-1,n-1});
        }
        else
        {
            if(a[pos+1]==1)
            {
                q.erase(pr{pos,pos});
                q.erase(pr{pos+1,pos+1});
                q.insert(pr{pos,pos+1});
            }
            else
            {
                q.erase(pr{pos,pos});
                q.insert(pr{pos,pos+1});
                q.insert(pr{pos+1,pos+1});
            }
        }
    }
    cout<<"YES\n";
    cout<<q.size()<<'\n';
    auto it=q.begin();
    while(it!=q.end())
    {
        cout<<(*it)[0]<<' '<<(*it)[1]<<'\n';
        ++it;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}