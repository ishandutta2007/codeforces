#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll,int>
#define x first
#define y second
typedef long long ll;
priority_queue < pii, vector <pii>, greater<pii> > pq;
vector <ll> v[100005],d[100005];
ll dis[100005];
int pa[100005],n,m;
vector <int> sol;
void pr()
{
    for(int i=1;i<=n;++i){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}
int main()
{

    cin>>n>>m;
    fill (dis,dis+100003,10000000000000);
    for(int i=0;i<m;++i){
        int x,y,dd;scanf("%d%d%d",&x,&y,&dd);
        v[x].push_back(y);
        v[y].push_back(x);
        d[x].push_back(dd);
        d[y].push_back(dd);
    }
    int st=1,en=n;
    pq.push({0,st});
    dis[st]=0;
    pa[1]=0;
    while(!pq.empty()){
        pii cur=pq.top();
        pq.pop();
        //cout<<cur.y <<" "<<cur.x<<endl;
       // pr();
        if(cur.x > dis[cur.y])continue;
        dis[cur.y]=cur.x;
        if(cur.y==en)break;
        for(int i=0;i<v[cur.y].size();++i){
            int nxt=v[cur.y][i];
            int cost=d[cur.y][i];
            if(cur.x+cost<dis[nxt]){
                pa[nxt]=cur.y;
                dis[nxt]=cur.x+cost;
                pq.push({dis[nxt],nxt});
            }
        }
    }
    //for(int i=1;i<=n;++i)cout<<dis[i];

    if(dis[en]==10000000000000){
        cout<<-1<<endl;
    }
    else{
        int cur=n;
        while(cur!=0){
            sol.push_back(cur);
            cur=pa[cur];
        }
        reverse(sol.begin(),sol.end());
        for(int i=0;i<sol.size();++i){
            printf("%d ",sol[i]);
        }
    }


}