#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int adj[2000000][26];
char a[2000000];
int pa[1000000];
int ans=0;
int cur=0;
string bad;
int k;
void dfs(int v,int x,int lev)
{
    if (v!=0)
        cur+=1-(bad[a[v]-'a']-'0');
    if (v!=0)
    {
        if (cur<=k)
            ans++;
    }
    for (int i=0;i<26;i++)
    {
        if (!adj[v][i])
            continue;
        pa[lev]=v;
        dfs(adj[v][i],x,lev+1);
    }
    if (v!=0)
    cur-=1-(bad[a[v]-'a']-'0');
}
int main()
{
    string s;
    cin>>s>>bad>>k;
    int n=s.length();
    int tot=0;
    for(int i=0;i<n;i++)
    {
        int j=i;
        int v=0;
        while(j<n)
        {
            if (adj[v][s[j]-'a']==0)
            {
                tot++;
                a[tot]=s[j];
                adj[v][s[j]-'a']=tot;
                v=tot;
            }
            else
                v=adj[v][s[j]-'a'];
            j++;
        }
    }
    dfs(0,1,0);
    cout<<ans<<endl;
}