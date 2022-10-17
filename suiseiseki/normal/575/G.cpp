#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
vector<pair<int,int> >edge[100005];
int father[100005],minn[100005],type[100005],stamp;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int u,v,len;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&len);
        edge[u].push_back(make_pair(v,len));
        edge[v].push_back(make_pair(u,len));
    }
    memset(type,-1,sizeof(type));
    type[n-1]=0;
    queue<int> q;
    q.push(n-1);
    queue<vector<int> > qq;
    qq.push(vector<int>());
    while(!q.empty()){
        u=q.front();
        q.pop();
        qq.front().push_back(u);
        for(unsigned i=0;i<edge[u].size();i++){
            v=edge[u][i].first;
            len=edge[u][i].second;
            if(type[v]==-1&&len==0){
                type[v]=0;
                father[v]=u;
                q.push(v);
            }
        }
    }
    vector<int> uu,visit,bucket[10];
    while(!qq.empty()){
        uu=qq.front();
        qq.pop();
        stamp++;
        visit.clear();
        for(unsigned i=0;i<uu.size();i++){
            u=uu[i];
            for(unsigned j=0;j<edge[u].size();j++){
                v=edge[u][j].first;
                len=edge[u][j].second;
                if(type[v]==-1){
                    type[v]=stamp;
                    visit.push_back(v);
                    father[v]=u;
                    minn[v]=len;
                }
                else if(type[v]==stamp&&len<minn[v]){
                    father[v]=u;
                    minn[v]=len;
                }
            }
        }
        for(int i=0;i<10;i++){
            bucket[i].clear();
        }
        for(unsigned i=0;i<visit.size();i++){
            u=visit[i];
            bucket[minn[u]].push_back(u);
        }
        for(int i=0;i<10;i++){
            if(!bucket[i].empty()){
                qq.push(bucket[i]);
            }
        }
    }
    vector<int> path;
    path.push_back(0);
    u=0;
    string ans;
    while(u!=n-1){
        if(type[u]){
            ans+=minn[u]+'0';
        }
        u=father[u];
        path.push_back(u);
    }
    if(!ans.empty()){
        reverse(ans.begin(),ans.end());
        puts(ans.c_str());
    }
    else{
        puts("0");
    }
    printf("%d\n",(int)path.size());
    for(int i=0;i<(int)path.size();i++){
        printf("%d ",path[i]);
    }
    puts("");
    return 0;
}