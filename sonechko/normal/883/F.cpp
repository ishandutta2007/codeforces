#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define all(a) a.begin(),a.end()
#define endl '\n'

using namespace std;

const int N=402;
const int inf=1e9+3;
const ll linf=1e18+3;
const int md=1e9+7;

int n,ans,sm;
string s,t;
string a[N];
bool used[N];
int bz;

vector<int> g[N];

void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<g[v].size();++i)
    {
        int to=g[v][i];
        if(used[to])continue;
        dfs(to);
    }
}

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            s=a[i];
            t=a[j];
            bool f=true;
            bz=0;
            for(int k=0;k<min(s.size(),t.size());++k)
            {
                bz++;
                if(bz>400)
                {
                    f=false;
                    break;
                }
                if(s[k]!=t[k])
                {
                    if(s[k]=='u')
                    {
                        s.erase(s.begin()+k);
                        s.insert(s.begin()+k,'o');
                        s.insert(s.begin()+k,'o');
                    }else if(t[k]=='u')
                    {
                        t.erase(t.begin()+k);
                        t.insert(t.begin()+k,'o');
                        t.insert(t.begin()+k,'o');
                    }else if(s[k]=='h')
                    {
                        s.erase(s.begin()+k);
                        s.insert(s.begin()+k,'h');
                        s.insert(s.begin()+k,'k');
                    }else if(t[k]=='h')
                    {
                        t.erase(t.begin()+k);
                        t.insert(t.begin()+k,'h');
                        t.insert(t.begin()+k,'k');
                    }
                    if(s[k]!=t[k])
                    {
                        f=false;
                        break;
                    }
                }
            }
            if(f&&s.size()!=t.size())f=false;
            if(f)g[i].pb(j),g[j].pb(i);
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(!used[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout<<ans;
}