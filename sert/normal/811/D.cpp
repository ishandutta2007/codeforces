#include <bits/stdc++.h>
using namespace std;
const int N = 105;

bool swap_lr, swap_ud;
int n, m, x = 0, y = 0;
string s[N], code = "UDLR";
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
int d[N][N], p[N][N];
int xx, yy;
int fx, fy;

void set_coord(int &x, int &y, char dir) {
    x++, y++;
    int nx = x;
    int ny = y;
    if (dir == 'L') x++;
    if (dir == 'R') x--;
    if (dir == 'U') y--;
    if (dir == 'D') y++;
    if (x < 1 || y < 1 || x > m || y > n || s[y - 1][x - 1] == '*') {
        x = nx;
        y = ny;
    }
}

bool go(int dir) { ///0 - up, 1 - down, 2 - left, 3 - right
    //cerr << "dir: " << dir << "\n";
    if ((dir > 1 && swap_lr) || (dir < 2 && swap_ud))
        dir ^= 1;
    cout << code[dir] << endl;
    xx = x, yy = y;
    cin >> y >> x;
    //set_coord(x, y, code[dir]);
    x--, y--;

    if (x == fx && y == fy) {
        //cerr << y << " " << x << " " << s[y][x] << "\n";
        exit(0);
    }
    return (x != xx || y != yy);
}

void set_up() {
    if (go(0)) {
        swap_ud = true;
        go(0);
    }
}

void set_left() {
    if (go(2)) {
        swap_lr = true;
        go(2);
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'F') {
                fx = j;
                fy = i;
            }
        }
    }
    if (s[0][1] != '*' && s[1][0] != '*') {
        set_up();
        set_left();
    } else if (s[0][1] != '*') {
        set_left();
        while (s[1][x] == '*')
            go(3);
        set_up();
    } else {
        set_up();
        while (s[y][1] == '*')
            go(1);
        set_left();
    }

    queue<pair<int, int>> q;
    q.push({x, y});
    d[y][x] = 1;
    p[y][x] = -1;

    //cerr << x << " " << y << "\n";

    int nx, ny;

    while (!q.empty()) {
        xx = q.front().first;
        yy = q.front().second;
        q.pop();
        if (s[yy][xx] == '*')
            continue;
        if (s[yy][xx] == 'F')
            break;
        for (int i = 0; i < 4; i++) {
            nx = xx + dx[i];
            ny = yy + dy[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || d[ny][nx])
                continue;
            d[ny][nx] = d[yy][xx] + 1;
            p[ny][nx] = i;
            q.push({nx, ny});
        }
    }

    vector <int> path;
    while (xx != x || y != yy) {
        path.push_back(p[yy][xx]);
        //cerr << "path_back: " << path.back() << "\n";
        yy -= dy[path.back()];
        xx -= dx[path.back()];
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < (int)path.size(); i++)
        go(path[i]);

    return 0;
}