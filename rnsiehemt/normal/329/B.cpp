#include <cstdio>
#include <queue>

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, -1, 0, 1 };

struct State {
    int y, x, d;
    State(int yy, int xx, int dd) : y(yy), x(xx), d(dd) { }
};

int Y, X;
char g[1005][1005];
bool seen[1005][1005];
State es(0,0,0);

int main()
{
    scanf("%d%d", &Y, &X);
    for (int y = 0; y < Y; y++) scanf(" %s", g[y]);

    {
        std::queue<State> q;
        for (int y = 0; y < Y; y++)
            for (int x = 0; x < X; x++)
                if (g[y][x] == 'S')
                    q.push(State(y, x, 0));
        while (!q.empty()) {
            State cur = q.front();
            q.pop();

            if (g[cur.y][cur.x] == 'E') {
                es = cur;
                break;
            }
            else if (seen[cur.y][cur.x]) continue;
            else seen[cur.y][cur.x] = true;

            for (int d = 0; d < 4; d++) {
                int ny = cur.y + dy[d];
                int nx = cur.x + dx[d];

                if (0 <= ny && ny < Y && 0 <= nx && nx < X && g[ny][nx] != 'T') {
                    q.push(State(ny, nx, cur.d+1));
                }
            }
        }
    }

    for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) seen[y][x] = false;
    int ans = 0;
    {
        std::queue<State> q;
        q.push(es);
        while (!q.empty()) {
            State cur = q.front(); q.pop();

            if (seen[cur.y][cur.x]) continue;
            else {
                seen[cur.y][cur.x] = true;
                if ('0' <= g[cur.y][cur.x] && g[cur.y][cur.x] <= '9') ans += g[cur.y][cur.x] - '0';
            }

            if (cur.d) {
                for (int d = 0; d < 4; d++) {
                    int ny = cur.y + dy[d];
                    int nx = cur.x + dx[d];

                    if (0 <= ny && ny < Y && 0 <= nx && nx < X && g[ny][nx] != 'T') {
                        q.push(State(ny, nx, cur.d-1));
                    }
                }
            }
        }
    }

    printf("%d\n", ans);
}