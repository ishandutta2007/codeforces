#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 1000100
using namespace std;
int N;
string s[MAXN];
int x, y; bool k;
int children[MAXN][2];
int parent[MAXN];
bool value[MAXN];
bool value2[MAXN];
void dfs(int node)
{
    for(int i=0; i<2; i++)
    {
        if(children[node][i]!=0)
        {
            dfs(children[node][i]);
        }
    }
    if(s[node] == "NOT")
    {
        value[node] = !value[children[node][0]];
    }
    if(s[node] == "AND")
    {
        value[node] = value[children[node][0]]&value[children[node][1]];
    }
    if(s[node] == "OR")
    {
        value[node] = value[children[node][0]]|value[children[node][1]];
    }
    if(s[node] == "XOR")
    {
        value[node] = value[children[node][0]]^value[children[node][1]];
    }
}
void dfs2(int node)
{
    if(node==1)
    {
        value2[node] = !value[node];
    }
    else
    {
        if(s[parent[node]] == "NOT")
        {
            value2[node] = value2[parent[node]];
        }
        if(s[parent[node]] == "OR")
        {
            value[node] = !value[node];
            k = value[children[parent[node]][0]]|value[children[parent[node]][1]];
            if(k != value[parent[node]])
            value2[node] = value2[parent[node]];
            else
            value2[node] = value[1];
            value[node] = !value[node];
        }
        if(s[parent[node]] == "AND")
        {
            value[node] = !value[node];
            k = value[children[parent[node]][0]]&value[children[parent[node]][1]];
            if(k != value[parent[node]])
            value2[node] = value2[parent[node]];
            else
            value2[node] = value[1];
            value[node] = !value[node];
        }
        if(s[parent[node]] == "XOR")
        {
            value[node] = !value[node];
            k = value[children[parent[node]][0]]^value[children[parent[node]][1]];
            if(k != value[parent[node]])
            value2[node] = value2[parent[node]];
            else
            value2[node] = value[1];
            value[node] = !value[node];
        }
    }
    for(int i=0; i<2; i++)
    {
        if(children[node][i]!=0)
        {
            dfs2(children[node][i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>s[i];
        if(s[i]=="NOT")
        {
            cin>>x;
            children[i][0] = x;
            parent[x] = i;
        }
        if(s[i]=="OR"||s[i]=="XOR"||s[i]=="AND")
        {
            cin>>x>>y;
            children[i][0] = x;
            children[i][1] = y;
            parent[x] = parent[y] = i;
        }
        if(s[i]=="IN")
        {
            cin>>value[i];
        }
    }
    dfs(1);
    dfs2(1);
    for(int i=1; i<=N; i++)
    {
        if(children[i][0] == 0)
        {
            cout<<value2[i];
        }
    }
}