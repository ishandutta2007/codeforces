#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAXN 100100
using namespace std;
struct element
{
    int a, b;
    element()
    {
        a = b = 0;
    }
    bool operator <(const element &rhs) const
    {
        return b<rhs.b;
    }
};
element c[MAXN];
int N;
int parent[MAXN];
bool vis[MAXN];
int counter;
vector<int> t[MAXN];
void dfs(int node)
{
    if(vis[node])
    {
        return;
    }
    vis[node] = true;
    t[counter].push_back(node);
    dfs(c[node].a);
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>c[i].b;
        c[i].a = i;
    }
    sort(c, c+N);
    for(int i=0; i<N; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            ++counter;
        }
    }
    cout<<counter<<endl;
    for(int i=0; i<counter; i++)
    {
        cout<<t[i].size()<<" ";
        for(int j=0; j<t[i].size(); j++)
        {
            cout<<t[i][j]+1<<" ";
        }
        cout<<""<<endl;
    }
}