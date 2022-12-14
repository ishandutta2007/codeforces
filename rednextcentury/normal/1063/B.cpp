#include <bits/stdc++.h>
using namespace std;
pair<int,int> dist[2001][2001];
int dd[2001][2001];
int n,m;
pair<int,int> D;
int r,c;
int mv[][3]={{0,1,2},{1,0,0},{0,-1,1},{-1,0,0}};
pair<int,int> operator+(pair<int,int> A,pair<int,int> B)
{
    return {A.first+B.first,A.second+B.second};
}
char a[2001][2001];
void bfs()
{
    for (int i=0; i<n; i++)
        for (int j=0;j<m;j++)
            dist[i][j]={1e9+6,1e9+6},dd[i][j]=1e9+6;
    deque <pair<int,int> > Q;
    dist[r][c] = {0,0};
    dd[r][c]=0;
    Q.push_back({r,c});

    while (!Q.empty())
    {
        pair<int,int> p = Q.front();
        Q.pop_front();

        r = p.first;
        c = p.second;

        for (int i=0; i<4; i++)
        {
            int R = r+mv[i][0];
            int C = c+mv[i][1];
            int W = mv[i][2];

            if (R>=n || R<0 || C>=m || C<0)continue;
            if (a[R][C]=='*')continue;
            if (W==0)
            {
                if (dd[R][C] > dd[r][c])
                {
                    dist[R][C] = dist[r][c];
                    dd[R][C]=dd[r][c];
                    Q.push_front({R,C});
                }
            }
            else if (W==1)
            {
                if (dd[R][C] > dd[r][c]+1)
                {
                    dist[R][C] = dist[r][c] + make_pair(1,0);
                    dd[R][C]=dd[r][c]+1;
                    Q.push_back({R,C});
                }
            }
            else
            {
                if(dd[R][C] > dd[r][c]+1)
                {
                    dist[R][C] = dist[r][c] + make_pair(0,1);
                    dd[R][C]=dd[r][c]+1;
                    Q.push_back({R,C});
                }
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>r>>c;
    cin>>D.first>>D.second;
    r--,c--;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    bfs();
    int ret=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (dist[i][j].first<=D.first && dist[i][j].second<=D.second)
                ret++;
    cout<<ret<<endl;
}