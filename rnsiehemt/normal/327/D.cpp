#include <cstdio>

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, -1, 0, 1 };

int Y, X;
char g[505][505];
bool seen[505][505];
char oc[750000];
int oy[750000];
int ox[750000];
int O;

void p(char c, int y, int x) {
    oc[O] = c;
    oy[O] = y;
    ox[O] = x;
    O++;
}

void dfs(int y, int x, bool root) {
    p('B', y, x);

    seen[y][x] = true;
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        
        if (0 <= ny && ny < Y && 0 <= nx && nx < X && g[ny][nx] == '.' && !seen[ny][nx])
            dfs(ny, nx, false);
    }

    if (!root) {
        p('D', y, x);
        p('R', y, x);
    }
}

int main()
{
    scanf("%d%d", &Y, &X);
    for (int y = 0; y < Y; y++) scanf(" %s", g[y]);
    
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            if (g[y][x] == '.' && !seen[y][x]) dfs(y, x, true);
    
    printf("%d\n", O);
    for (int o = 0; o < O; o++) printf("%c %d %d\n", oc[o], oy[o]+1, ox[o]+1);
}