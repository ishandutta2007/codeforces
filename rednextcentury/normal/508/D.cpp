#include <bits/stdc++.h>
using namespace std;
string a[1000000];
vector<int> adj[1000000];
map<int,int> mp;
int nd = 0;
map<int,int> rmp;
int Get(int x)
{
    if (mp[x]==0)
        mp[x]=++nd;
    rmp[mp[x]]=x;
    return mp[x];
}
int deg[1000000];
int getStart()
{
    int id = 1;
    int cnt1 = 0, cnt2 =0;
    for (int i=1;i<=nd;i++)
    {
        if (abs(deg[i])>1)
            return -1;
        if (deg[i]==-1)
            cnt1++,id=i;
        if (deg[i]==1)
            cnt2++;
    }
    if (cnt1+cnt2==0)
        return 1;
    if (cnt1==1 && cnt2==1)
        return id;
    return -1;
}
stack<int> s;
vector<int> ret;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        int u = a[i][0]*300+a[i][1];
        u = Get(u);
        int v = a[i][1]*300+a[i][2];
        v = Get(v);
        adj[u].push_back(v);
        deg[u]--;
        deg[v]++;
    }
    int st = getStart();
    if (st==-1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    while(1)
    {
        if (adj[st].size()==0)
        {
            ret.push_back(st);
            if (s.empty())
                break;
            st = s.top();
            s.pop();
        }
        else
        {
            int v = adj[st][adj[st].size()-1];
            adj[st].pop_back();
            s.push(st);
            st = v;
        }
    }
    if (ret.size()!=n+1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    int c = ret[ret.size()-1];
    c = rmp[c];
    cout<<char(c/300)<<char(c%300);
    for (int i=ret.size()-2;i>=0;i--)
    {
        int c = rmp[ret[i]];
        cout<<char(c%300);
    }
    cout<<endl;
}