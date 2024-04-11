/*
!!
*/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int NICO = 2002;
int n, m, dot;
char mp[NICO][NICO];
char res[NICO][NICO];
int cnt[NICO][NICO];
int sta[NICO][NICO];
char gou[4] = {'>','<','v','^'};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pii> q;
bool ok(int x, int y)
{
    return (x<=n) && (x>=1) && (y<=m) && (y>=1) && (mp[x][y] == '.');
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        scanf("%s", mp[i] + 1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j] != '.') continue;
            dot ++;
            for(int k=0;k<4;k++)
            {
                int cx = i+dx[k];
                int cy = j+dy[k];
                if(ok(cx, cy))
                {
                    cnt[i][j] ++;
                    sta[i][j] = k;
                }
            }
            if(cnt[i][j] == 1) 
            {
                q.push(make_pair(i,j));
            }
        }
    }
    int res = 0;

    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(mp[i][j] != '.') continue;
        int dir = sta[i][j];
        mp[i][j] = gou[(dir<=1)?(1-dir):(5-dir)]; 
        int x = i+dx[dir];
        int y = j+dy[dir];
        mp[x][y] = gou[dir];
        res += 2;
        for(int k=0;k<4;k++)
        {
            int cx = x+dx[k];
            int cy = y+dy[k];
            if(ok(cx, cy))
            {
                cnt[cx][cy] --;
                if(cnt[cx][cy] == 1)
                {
                    q.push(make_pair(cx, cy));
                    if(ok(cx,cy+1)) sta[cx][cy] = 0;
                    if(ok(cx,cy-1)) sta[cx][cy] = 1;
                    if(ok(cx+1,cy)) sta[cx][cy] = 2;
                    if(ok(cx-1,cy)) sta[cx][cy] = 3;
                }
            }
        }
    }

    if(res != dot)
    {
        cout << "Not unique" << endl;
        return 0;
    } 

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%c", mp[i][j]);
        }
        printf("\n");
    }
}