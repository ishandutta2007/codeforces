#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2222;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char table[N][N];
int degree[N][N];
vector<pair<int, int> > queue;
int total;

int n, m;

void error() {
    puts("Not unique");
    exit(0);
}

void delet(int x, int y) {
    for(int k = 0; k < 4; k++) {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (xx < 1 || xx > n || yy < 1 || yy > m || table[xx][yy] == '*') {
            continue;
        }
        if (--degree[xx][yy] == 1) {
            queue.push_back(make_pair(xx, yy));
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", table[i] + 1);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if (table[i][j] == '*') {
                continue;
            } else {
                total++;
                for(int k = 0; k < 4; k++) {
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if (ii < 1 || ii > n || jj < 1 || jj > m || table[ii][jj] == '*') {
                        continue;
                    }
                    degree[ii][jj]++;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if (degree[i][j] == 1) {
                queue.push_back(make_pair(i, j));
            }
        }
    }
    for(int head = 0; head < (int)queue.size(); head++) {
        pair<int, int> tmp = queue[head];
        if (table[tmp.first][tmp.second] != '.') {
            continue;
        }
        if (degree[tmp.first][tmp.second] != 1) {
            //printf("%d\n", degree[tmp.first][tmp.second]);
            error();
        }

        int cx, cy;
        for(int k = 0; k < 4; k++) {
            int x = tmp.first + dx[k];
            int y = tmp.second + dy[k];
            if (x < 1 || x > n || y < 1 || y > m || table[x][y] != '.') {
                continue;
            }
            if (x > tmp.first) {
                table[tmp.first][tmp.second] = '^';
                table[x][y] = 'v';
            } else if (x < tmp.first) {
                table[tmp.first][tmp.second] = 'v';
                table[x][y] = '^';
            } else if (y > tmp.second) {
                table[tmp.first][tmp.second] = '<';
                table[x][y] = '>';
            } else {
                table[tmp.first][tmp.second] = '>';
                table[x][y] = '<';
            }
            cx = x, cy = y;
        }
        delet(cx, cy);
        delet(tmp.first, tmp.second);
        total -= 2;
    }
    if (total) {
        error();
    }
    for(int i = 1; i <= n; i++) {
        puts(table[i] + 1);
    }
    return 0;
}