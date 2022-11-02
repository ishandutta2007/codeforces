#include<stdio.h>
#include<memory.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define N 600

vector<int>v[N];
queue<int>q;
int n;
int deg[N];
int vis[N];
int fg[N];
struct dat{
    int x, y;
    dat(int x = 0, int y = 0) : x(x), y(y){}
}p[N];
bool cmp(dat a, dat b){
    return min(a.x, a.y) > min(b.x, b.y);
}
bool chk(){
    for(int i = 1; i <= n; i ++)if(deg[i] > 2)return 0;
    return 1;
}

int main(){
    int m, x, y, last;
 //   freopen("E.in","r",stdin);
    while(scanf("%d%d", &n, &m) == 2){
        int mm = m;
        for(int i = 1; i <= n; i ++)v[i].clear();
        memset(deg, 0, sizeof(deg));
        memset(vis,0, sizeof(vis));
        while(m --){
            scanf("%d%d", &x, &y);
            deg[x] ++, deg[y] ++;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int cnt = 0, link = 0, b = 0;
        if(!chk()){puts("NO");continue;}
        for(int i = 1; i <= n; i ++)if(!vis[i] && deg[i] <= 1){
            q.push(i), vis[i] = 1, b ++;
            while(!q.empty()){
                int j = q.front();
                last = j, q.pop();
                for(int k = 0; k < v[j].size(); k ++)if(!vis[v[j][k]]){
                    q.push(v[j][k]);
                    vis[v[j][k]] = 1;
                }
            }
            p[cnt ++] = dat(i, last);
        }
         for(int i = 1; i <= n; i ++)if(!vis[i] && deg[i] == 2){
            q.push(i);
            vis[i] = 1;
            link ++;
            while(!q.empty()){
                int j = q.front();
                last = j;
                q.pop();
                for(int k = 0; k < v[j].size(); k ++)if(!vis[v[j][k]]){
                    q.push(v[j][k]);
                    vis[v[j][k]] = 1;
                }
            }
        }
        if(link){
            if(link == 1 && !b){puts("YES");puts("0"); continue;}
            puts("NO"); continue;
        }
        puts("YES");
        printf("%d\n", n - mm);
        while(1){
            if(cnt > 1){
                sort(p, p + cnt, cmp);
                int xx = min(p[cnt-2].x, p[cnt-2].y);
                int yy = min(p[cnt-1].x, p[cnt-1].y);
                printf("%d %d\n", min(xx, yy), max(xx, yy));
                if(p[cnt-2].x <= p[cnt-2].y)
                    p[cnt-2].x = max(p[cnt-1].x, p[cnt-1].y);
                else p[cnt-2].y = max(p[cnt-1].x, p[cnt-1].y);
            }
            if(cnt == 1){printf("%d %d\n", min(p[0].x, p[0].y), max(p[0].x, p[0].y));break;}
            cnt --;
        }
    }
}