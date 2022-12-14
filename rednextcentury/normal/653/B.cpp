#include <bits/stdc++.h>
using namespace std;
vector<string> adj[10000];
set<string> s;
map<string,bool> vis;
int n;
void bfs()
{
    string h="a";
    queue<string> q;
    q.push(h);
    vis[h]=1;
    while(!q.empty())
    {
        string x=q.front();
        q.pop();
        if (x.length()==n)
        {
            s.insert(x);
            continue;
        }
        for (int i=0;i<adj[x[0]-'a'].size();i++)
        {
            string y=adj[x[0]-'a'][i]+x.substr(1,x.size()-1);
            if (!vis[y])
            {
                vis[y]=1;
                q.push(y);
            }
        }
    }
}
int main()
{
    int q;
    cin>>n>>q;
    for (int i=0;i<q;i++)
    {
        string a;
        char x;
        cin>>a>>x;
        adj[x-'a'].push_back(a);
    }
    bfs();
    cout<<s.size()<<endl;
}