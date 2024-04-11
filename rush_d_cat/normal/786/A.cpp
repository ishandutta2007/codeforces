#include <iostream>
#include <queue>
using namespace std;
const int NICO = 200000+10;
typedef pair<int, int> pii;
int n, k1, k2;
int s1[NICO], s2[NICO], dp[NICO][2], us[NICO][2], ct[NICO][2];
void bfs()
{
    queue<pii> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = -1;us[0][0] = 1;
    q.push(make_pair(0, 0));
    dp[0][1] = 1;us[0][1] = 1;
    q.push(make_pair(0, 1));
    while(q.size())
    {
        pii cur = q.front();
        q.pop();
        int xx = cur.first;
        int yy = cur.second;

        if(yy == 0)
        {
            for(int i=1;i<=k2;i++) 
            {
                int px = (xx - s2[i] + n) % n;
                int py = 1;
                if(us[px][py]) continue;
                if(dp[xx][yy] == 1)
                {
                    ct[px][py] ++;
                    if(ct[px][py] == k2)
                    {
                        dp[px][py] = 1;us[px][py] = 1;
                        q.push(make_pair(px, py));
                    }
                }
                if(dp[xx][yy] == -1)
                {
                    dp[px][py] = -1;us[px][py] = 1;
                    q.push(make_pair(px, py));
                }
            }
        }
        if(yy == 1)
        {
            for(int i=1;i<=k1;i++) 
            {
                int px = (xx - s1[i] + n) % n;
                int py = 0;
                if(us[px][py]) continue;
                if(dp[xx][yy] == -1)
                {
                    ct[px][py] ++;
                    if(ct[px][py] == k1)
                    {
                        dp[px][py] = -1;us[px][py] = 1;
                        q.push(make_pair(px, py));
                    }
                }
                if(dp[xx][yy] == 1)
                {
                    dp[px][py] = 1;us[px][py] = 1;
                    q.push(make_pair(px, py));
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &k1);
    for(int i=1;i<=k1;i++)
    {
        scanf("%d", &s1[i]);
    }
    scanf("%d", &k2);
    for(int i=1;i<=k2;i++)
    {
        scanf("%d", &s2[i]);
    }
    bfs();
    for(int i=1;i<n;i++)
    {
        if(dp[i][0] == 1)
        {
            printf("Win ");
        }
        if(dp[i][0] == -1)
        {
            printf("Lose ");
        }
        if(dp[i][0] == 0)
        {
            printf("Loop ");
        }
    }
    printf("\n");
    for(int i=1;i<n;i++)
    {
        if(dp[i][1] == -1)
        {
            printf("Win ");
        }
        if(dp[i][1] == 1)
        {
            printf("Lose ");
        }
        if(dp[i][1] == 0)
        {
            printf("Loop ");
        }
    }
}