#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
vector<string> v;
vector<vector<bool> > valid;
vector<vector<int> > dis;
vector<vector<P> >pre;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int ddx[4]={-1,-1,1,1},ddy[4]={-1,1,-1,1};
void upd(int &a,int b) {a=min(a,b);}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        v.clear();
        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            v.push_back(str);
        }
        valid.clear(); valid.resize(n); 
        for(int i=0;i<n;i++)
        {
            valid[i].resize(m);
            for(int j=0;j<m;j++) valid[i][j]=true;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='#')
                {
                    valid[i][j]=false;
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+dx[k],ny=j+dy[k];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m) valid[nx][ny]=false;
                    }
                }
            }
        }
        dis.clear();dis.resize(n); pre.clear(); pre.resize(n);
        deque<P> que;
        for(int i=0;i<n;i++)
        {
            dis[i].resize(m); pre[i].resize(m);
            for(int j=0;j<m;j++) pre[i][j]=P(-1,-1);
            for(int j=0;j<m;j++) 
            {
                dis[i][j]=INF;
                if(j==0) 
                {
                    dis[i][j]=(v[i][j]=='#'?0:(valid[i][j]?1:INF));
                    if(dis[i][j]==0) que.push_front(P(i,j)); else if(dis[i][j]==1) que.push_back(P(i,j));
                }
            }
        }
        while(que.size())
        {
            P p=que.front(); que.pop_front();
            int x=p.F,y=p.S;
            if(y==m-1) break;
            int d=dis[x][y];
            for(int k=0;k<4;k++)
            {
                int nx=x+ddx[k],ny=y+ddy[k];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                int ndis=dis[x][y]+(v[nx][ny]=='#'?0:(valid[nx][ny]?1:INF));
                if(dis[nx][ny]>ndis)
                {
                    dis[nx][ny]=ndis; pre[nx][ny]=P(x,y);
                    if(ndis==d) que.push_front(P(nx,ny)); else que.push_back(P(nx,ny));
                }
            }
        }
        int id=0;
        for(int i=1;i<n;i++) if(dis[i][m-1]<dis[id][m-1]) id=i;
        if(dis[id][m-1]==INF) {puts("NO"); continue;}
        int x=id,y=m-1;
        while(x!=-1)
        {
            v[x][y]='#';
            P p=pre[x][y];
            x=p.F; y=p.S;
        }
        puts("YES");
        for(int i=0;i<n;i++) cout<<v[i]<<endl;
    }
    return 0;
}