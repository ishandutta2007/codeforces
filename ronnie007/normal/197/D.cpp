#include <cstdio>
#include <cstring>

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n, m;
int sx, sy;
char t[1520][1520];
int us[1520][1520];
bool novis[1520][1520];

bool dfs( int x, int y, int px, int py );

int main()
    {
    int i, j, k;

    scanf( "%d %d", &n, &m );

    for (i=0; i<n;i++)
        {
        scanf("%s",t[i]);
        }

    ///memset(us,0,sizeof(us));
    ///memset(novis,0,sizeof(novis));

    for (i=0; i<n;i++)
        {
        for (j=0;j<m;j++)
            {
            if (t[i][j]=='S')
                {
                us[i][j]=1;
                if (dfs(i,j,-1,-1))
                    {
                    printf("Yes\n");
                    return 0;
                    }
                }
            }
        }
    printf("No\n");
    return 0;
    }





bool dfs( int x, int y, int px, int py )
    {
    int i, nx, ny;
    int ne, cx, cy;
    for(i=0;i<4;i++)
        {
        ne=0;
        cx=x+dx[i];
        cy=y+dy[i];

        if (cx>=n )ne=1;
        if (cx<0 )ne=-1;
        if (cy>=m )ne=100000;
        if (cy<0 )ne=-100000;

        nx=(x+dx[i]+n)%n;
        ny=(y+dy[i]+m)%m;
        if((nx==px) && (ny ==py)) continue;
        if(t[nx][ny]=='.' || t[nx][ny]=='S' )
            {
            if(!novis[nx][ny])
                {
                novis[nx][ny]=1;
                us[nx][ny]=us[x][y]+ne;
                if(dfs(nx,ny,x,y )) return 1;
                }
            else if(us[nx][ny]!=us[x][y]+ne )
                {
                return 1;
                }
            }
        }
    return 0;
    }