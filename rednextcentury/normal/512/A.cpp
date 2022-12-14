# include <iostream>
# include <algorithm>
# include <vector>
# include <stack>
using namespace std;
vector<int> adj[1000000];
string b[1000000];
int len[1000000];
bool is=0;
int st;
stack<int> ans;
bool vis[1000];
    bool visi[26]={0};
void check(int v)
{
    visi[v]=1;
    int n=adj[v].size();
    for (int j=0;j<n;j++)
    {
        int u=adj[v][j];
        if (u==st)
            is=1;
        if (visi[u])
            continue;
        check(u);
    }
}
void toposort(int v)
{
    vis[v]=1;
    int n=adj[v].size();
    for (int j=0;j<n;j++)
    {
        int u=adj[v][j];
        if (vis[u])
            continue;
        toposort(u);
    }
    ans.push(v);
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>b[i];
        len[i]=b[i].length();
    }
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            int k=min(len[i],len[j]);
            bool o=0;
            for (int x=0;x<k;x++)
            {
                if (b[i][x]!=b[j][x])
                {
                    adj[(int)b[i][x]-'a'].push_back((int)b[j][x]-'a');
                    o=1;
                    break;
                }
            }
            if (o==0 && len[j]<len[i])
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    for (int i=0;i<26;i++)
    {
        for (int j=0;j<26;j++)
            visi[j]=0;
        st=i;
        check(i);
    }
    if (is)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    for (int i=0;i<26;i++)
    {
        if (!vis[i])
        toposort(i);
    }
    while(!ans.empty())
    {
        cout<<char(ans.top()+'a');
        ans.pop();
    }
    cout<<endl;
}