#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 222

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

char s[N];
bool vis[N][N];

int main(){
    scanf("%s", s);
    int len = strlen(s);

    int x = 111, y = 111;
    vis[x][y] = 1;

    for(int i=0; i<len; i++){
        if(s[i] == 'R') x ++;
        if(s[i] == 'L') x --;
        if(s[i] == 'U') y ++;
        if(s[i] == 'D') y --;
        if(vis[x][y]) {puts("BUG"); return 0;}
        int cnt = 0;
        for(int k=0; k<4; k++) if(vis[x+dx[k]][y+dy[k]]) cnt ++;
        if(cnt > 1) {puts("BUG"); return 0;}
        vis[x][y] = 1;
    }
    puts("OK");
}