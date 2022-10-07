#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 51;
bool vis[MAXN][MAXN][MAXN][MAXN];
char grid[MAXN][MAXN];
const int mx[4] = {-1,0,1,0};
const int my[4] = {0,1,0,-1};
int N, M;
int main() {
scanf("%d %d", &N, &M);
for(int i = 0; i < N; ++i) {
scanf("%s", grid[i]);
}


for(int a = 0; a < N; ++a) {
for(int b = 0; b < M; ++b) {
    if(grid[a][b]=='W') continue;
    vector<int> vx, vy;
    int num = 0;
    for(int d = 0; d < 4; ++d){
    int curx = a;
    int cury = b;
    while(curx>=0&&cury>=0&&curx<N&&cury<M) {
    if(grid[curx][cury]=='W') break;
vx.push_back(curx);
vy.push_back(cury);
++num;
    curx+=mx[d];
    cury+=my[d];
    }}
    for(int i = 0; i < num; ++i){
    for(int j = 0; j < num; ++j) {
    vis[vx[i]][vy[i]][vx[j]][vy[j]] = true;}}
 }
 }  
 bool ans = true;
 for(int i = 0; i < N; ++i){
 for(int j = 0;j<M;++j){if(grid[i][j]=='W') continue;
 for(int a = 0;a<N; ++a){
 for(int b = 0; b < M; ++b){if(grid[a][b]=='W') continue;
 if(!vis[i][j][a][b])
 {ans = false;
 break;
 }
 }
 }}
 }
 if(ans)printf("YES\n");
 else printf("NO\n");
 return 0;
 }