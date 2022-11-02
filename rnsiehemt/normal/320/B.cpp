#include <cstdio>
#include <algorithm>
#include <vector>

int N;
std::vector<int> x, y;
bool seen[105];

bool dfs(int at, int aim) {
    if (seen[at]) return false;
    if (at == aim) return true;
    else seen[at] = true;

    for (int i = 0; i < (int)x.size(); i++) {
        if ((x[i] < x[at] && x[at] < y[i]) ||
            (x[i] < y[at] && y[at] < y[i]))
        {
            if (dfs(i, aim)) return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int cmd, a, b; scanf("%d%d%d", &cmd, &a, &b);
        if (cmd == 1) {
            x.push_back(a); y.push_back(b);
        }
        else /* cmd == 2 */ {
            std::fill(seen, seen+103, false);
            printf("%s\n", dfs(a-1, b-1) ? "YES" : "NO");
        }
    }
}