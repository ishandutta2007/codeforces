#include <iostream>
#define MAXN 200200
using namespace std;
int use[MAXN];
int gf[MAXN];
int s[MAXN];
int t[MAXN];
int N;
void dfs(int node, int lvl)
{
    if(use[node] !=0)
    {
        return;
    }
    else
    {
        use[node] = lvl;
        dfs(gf[node], lvl%2+1);
        if(node%2==0)
        {
            dfs(node-1, lvl%2+1);
        }
        else
        {
            dfs(node+1, lvl%2+1);
        }
    }
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>s[i]>>t[i];
        gf[s[i]] = t[i];
        gf[t[i]] = s[i];
    }
    for(int i=1; i<=2*N; i++)
    {
        if(use[i]==0)
        {
            dfs(i, 1);
        }
    }
    for(int i=0; i<N; i++)
    {
        cout<<use[s[i]]<<" "<<use[t[i]]<<endl;
    }
}