#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e3+5;

typedef pair <int,int> pii;
#define x first
#define y second

pii a[sz][sz];
char ans[sz][sz];
bool vis[sz][sz];

int dir[] = {-1, 0, 1, 0, 0, 1, 0, -1};
char w[] = "DDUULLRR", wi[] = "UUDDRRLL";

int main()
{
    int n;
    cin >> n;
    queue <pii> q;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d %d", &a[i][j].x, &a[i][j].y);
            if(a[i][j]==make_pair(i,j)) {
                vis[i][j]=1, ans[i][j]='X';
                q.push({i,j});
            }
        }
    }

    while(!q.empty()) {
        pii nxt = q.front();
        q.pop();

        for(int i=0; i<8; i+=2) {
            pii now;
            now.x = nxt.x + dir[i];
            now.y = nxt.y + dir[i+1];
            if(!now.x || !now.y || now.x>n || now.y>n) continue;
            if(vis[now.x][now.y]) continue;

            if(a[now.x][now.y]==a[nxt.x][nxt.y]) {
                vis[now.x][now.y]=1;
                ans[now.x][now.y]=w[i];
                q.push(now);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(vis[i][j]) continue;
            if(a[i][j].x<0) {
                pii nxt = {i,j};
                for(int k=0; k<8; k+=2) {
                    pii now;
                    now.x = nxt.x + dir[k];
                    now.y = nxt.y + dir[k+1];
                    if(!now.x || !now.y || now.x>n || now.y>n) continue;

                    if(a[now.x][now.y].x<0) {
                        vis[i][j]=1;
                        ans[i][j]=wi[k];
                        break;
                    }
                }
            }

            if(!vis[i][j]) {
                puts("INVALID");
                return 0;
            }
        }
    }

    puts("VALID");
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%c", ans[i][j]);
        }
        puts("");
    }
}