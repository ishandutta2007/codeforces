#include<iostream>
#include<vector>

using namespace std;

int par[300001],ch[300001],d[300001];
int dp[300001];
bool used[300001];

vector<int> v[300001];

void findParent(int x)
{
    if(x==par[x])
        return;

    findParent(par[x]);

    par[x]=par[par[x]];

    return;
}

bool unite(int a,int b)
{
    findParent(a);
    findParent(b);

    if(par[a]==par[b])
        return 0;

    if(ch[par[a]]<ch[par[b]])
        swap(a,b);

    d[par[a]]=max(max(d[par[a]],d[par[b]]),d[par[a]]/2+d[par[a]]%2+d[par[b]]/2+d[par[b]]%2+1);
    //cout<<d[par[a]]<<endl;
    ch[par[a]]+=ch[par[b]];
    par[par[b]]=par[a];

    return 1;
}

bool uniteNO(int a,int b)
{
    findParent(a);
    findParent(b);

    if(par[a]==par[b])
        return 0;

    if(ch[par[a]]<ch[par[b]])
        swap(a,b);

    ch[par[a]]+=ch[par[b]];
    par[par[b]]=par[a];

    return 1;
}

pair<int,int> findD(int u,int parent)
{
    used[u]=1;

    int i,g1=0,g2=0;
    pair<int,int> res=make_pair(0,0),Pair;

    for(i=0;i<v[u].size();i++)
    {
        if(v[u][i]==parent)
            continue;

        Pair=findD(v[u][i],u);

        if(Pair.first>res.first)
            res.first=Pair.first;

        if(Pair.second>g1)
        {
            g2=g1;
            g1=Pair.second;
        }
        else
        {
            if(Pair.second>g2)
                g2=Pair.second;
        }
    }

    g1++;
    res.first=max(res.first,g1+g2);
    res.second=g1;

    return res;
}

void diameter(int u,int parent,int val)
{
    int i;

    d[u]=val;

    for(i=0;i<v[u].size();i++)
    {
        if(v[u][i]==parent)
            continue;

        diameter(v[u][i],u,val);
    }
}

int main ()
{
    int n,m,q,a,b,i;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>q;

    for(i=1;i<=n;i++)
    {
        par[i]=i;
        ch[i]=1;
        d[i]=0;
    }

    for(i=0;i<m;i++)
    {
        cin>>a>>b;

        v[a].push_back(b);
        v[b].push_back(a);

        uniteNO(a,b);
    }

    for(i=1;i<=n;i++)
        if(!used[i])
            diameter(i,-1,findD(i,-1).first-1);

    for(i=0;i<q;i++)
    {
        cin>>a;

        if(a==1)
        {
            cin>>b;

            findParent(b);

            cout<<d[par[b]]<<"\n";
        }
        else
        {
            cin>>a>>b;

            unite(a,b);
        }
    }

    return 0;
}