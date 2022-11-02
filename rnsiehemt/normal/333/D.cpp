#include <cstdio>
#include <vector>

int Y, X;
int g[1005][1005];
bool seen[1005][1005];

bool f(int a) {
    for (int x1 = 0; x1 < X; x1++) for (int x2 = x1+1; x2 < X; x2++) seen[x1][x2] = false;
    for (int y = 0; y < Y; y++) {
        std::vector<int> v;
        for (int x = 0; x < X; x++) if (g[y][x] >= a) v.push_back(x);
        for (int i = 0; i < (int)v.size(); i++) {
            for (int j = i+1; j < (int)v.size(); j++) {
                if (seen[v[i]][v[j]]) return true;
                else seen[v[i]][v[j]] = true;
            }
        }
    }
    /* else */ return false;
}

int main()
{
    scanf("%d%d", &Y, &X);
    for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) scanf("%d", &g[y][x]);

    int lo = 0, hi = 1000000001;
    while (hi-lo > 1) {
        int mid = (lo+hi)/2;
        if (f(mid)) lo = mid;
        else hi = mid;
    }

    printf("%d\n", lo);
}