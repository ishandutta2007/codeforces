#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define MAXN 100100
using namespace std;
int N, M;
vector<int> conn[MAXN];
int deg[MAXN];
int E[MAXN];
queue<int> q1;
queue<int> q2;
int x, y;
int v, ans;
void dfsm()
{
    while(!q1.empty())
    {
        v = q1.front();
        q1.pop();
        --N;
        for(int i=0; i<conn[v].size(); i++)
        {
            deg[conn[v][i]]--;
            if(deg[conn[v][i]]==0)
            {
                if(E[conn[v][i]]==0)
                {
                    q1.push(conn[v][i]);
                }
                else
                {
                    q2.push(conn[v][i]);
                }
            }
        }
    }
}
void dfsc()
{
    while(!q2.empty())
    {
        v = q2.front();
        q2.pop();
        --N;
        for(int i=0; i<conn[v].size(); i++)
        {
            deg[conn[v][i]]--;
            if(deg[conn[v][i]]==0)
            {
                if(E[conn[v][i]]==0)
                {
                    q1.push(conn[v][i]);
                }
                else
                {
                    q2.push(conn[v][i]);
                }
            }
        }
    }
}
int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        cin>>E[i];
    }
    for(int i=0; i<M; i++)
    {
        cin>>x>>y;
        conn[y].push_back(x);
        deg[x]++;
    }
    for(int i=0; i<N; i++)
    {
        if(deg[i]==0&&E[i]==0)
        {
            q1.push(i);
        }
        else if(deg[i]==0&&E[i]==1)
        {
            q2.push(i);
        }
    }
    while(N>=0)
    {
        dfsm();
        if(N==0)
        {
            break;
        }
        dfsc();
        ++ans;
    }
    cout<<ans<<endl;
}