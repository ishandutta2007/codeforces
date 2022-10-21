#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500;
typedef pair<int, int> P;

int n,a,lar = 0;
int r,c,xi,yi;
int freq[N];
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

bool in_bound(int x, int y){
    return x >= 0 && x < r && y >= 0 && y < c;
}

bool check(){
    if(!in_bound(xi, yi)) return false;
    bool vis[r][c];
    int num[r][c], fre[n];
    queue<P> que;
    for(int i = 0; i < r; i++) fill(vis[i], vis[i]+c, false);
    fill(fre, fre+n, 0);
    vis[xi][yi] = 1, num[xi][yi] = 0;
    que.push({xi, yi});
    while(!que.empty()){
        P p = que.front(); que.pop();
        for(int t = 0; t < 4; t++){
            int nx = p.first + dx[t], ny = p.second + dy[t];
            if(in_bound(nx, ny) && !vis[nx][ny]){
                vis[nx][ny] = 1;
                num[nx][ny] = num[p.first][p.second] + 1;
                que.push({nx, ny});
                fre[num[nx][ny]] ++;
            }
        }
    }
    for(int i = 1; i < n; i++) if(fre[i] != freq[i]) return false;
    return true;

}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a), freq[a]++, lar = max(lar, a);

    for(xi = 1; xi < N; xi++) if(freq[xi] != 4 * xi) break;
    xi--;


    for(int i = 1; i <= n; i++){
        if(n % i != 0) continue;
        r = n / i, c = i; yi = r + c - lar - 2 - xi;
        if(check()){
            printf("%d %d\n%d %d\n", r, c, xi+1, yi+1);
            return 0;
        }
    }
    printf("-1");

}