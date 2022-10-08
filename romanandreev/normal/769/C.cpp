#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

constexpr int NMAX = 1e3 + 5;

int n, m, k;
int robot_x, robot_y;
char field[NMAX][NMAX];
int distance[NMAX][NMAX];

const int dx[4] = { 1, 0, 0, -1 };
const int dy[4] = { 0, -1, 1, 0 };
const char dnames[] = "DLRU";

void read() {
    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s\n", field[i]);

        for (int j = 0; j < m; ++j) {
            if (field[i][j] == 'X') {
                robot_x = i;
                robot_y = j;
            }
        }
    }
}

void build_distance(int x, int y) {
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    std::queue<std::pair<int, int>> queue;
    visited[x][y] = true;
    distance[x][y] = 0;
    queue.push({x, y});

    while (!queue.empty()) {
        x = queue.front().first;
        y = queue.front().second;
        queue.pop();

        for (int i = 0; i < 4; ++i) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if (!(0 <= x1 && x1 < n && 0 <= y1 && y1 < m))
                continue;
            if (visited[x1][y1])
                continue;
            if (field[x1][y1] == '*')
                continue;

            distance[x1][y1] = distance[x][y] + 1;
            visited[x1][y1] = true;
            queue.push({x1, y1});
        }
    }
}

std::string get_answer() {
    std::string result = "";

    for (int turn = 0; turn < k; ++turn) {
        int next_step = -1;
        for (int i = 0; i < 4; ++i) {
            int x = robot_x + dx[i];
            int y = robot_y + dy[i];
            if (!(0 <= x && x < n && 0 <= y && y < m))
                continue;
            if (field[x][y] == '*')
                continue;
            if (distance[x][y] > k - turn - 1)
                continue;
            next_step = i;
            robot_x = x;
            robot_y = y;
            break;
        }
        if (next_step == -1)
            return "IMPOSSIBLE";
        result += dnames[next_step];
    }
    return result;
}

int main() {
    read();
    build_distance(robot_x, robot_y);
    std::string answer = get_answer();
    printf("%s\n", answer.c_str());
}