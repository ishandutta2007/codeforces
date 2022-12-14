#include <bits/stdc++.h>
using namespace std;
bool vis[5001][501];
pair<int,pair<int,int> > b[5001][501];
int d,s;
void bfs()
{
    queue<pair<int,int> > q;
    q.push({s,0});
    vis[s][0]=1;
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int S = p.first;
        int D = p.second;
        for (int i=0;i<10;i++)
        {
            int SS = S-i;
            int DD = (D*10+i)%d;
            if (SS<0 || vis[SS][DD])continue;
            vis[SS][DD]=1;
            b[SS][DD]={i,{S,D}};
            q.push({SS,DD});
        }
    }
}
int main()
{
    cin>>d>>s;
    bfs();
    if (vis[0][0])
    {
        string ret="";
        int S = 0;
        int D = 0;
        while(S!=s || D!=0)
        {
            pair<int,pair<int,int> > p = b[S][D];
            ret+=p.first+'0';
            S = p.second.first;
            D = p.second.second;
        }
        reverse(ret.begin(),ret.end());
        cout<<ret<<endl;
    }
    else
        cout<<-1<<endl;
}