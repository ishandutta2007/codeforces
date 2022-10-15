#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
double coords[5005][2];
double f[2505][5005][2];

double dist(int a, int b)
{
    return sqrt((coords[a][0] - coords[b][0]) * (coords[a][0] - coords[b][0]) +
                (coords[a][1] - coords[b][1]) * (coords[a][1] - coords[b][1]));
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &(coords[i][0]), &(coords[i][1]));
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        coords[i][0] = coords[i-n][0];
        coords[i][1] = coords[i-n][1];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j + i - 1 <= n * 2; j++) {
            f[i][j][0] = max(f[i-1][j+1][0] + dist(j, j+1),
                             f[i-1][j+1][1] + dist(j, j+i-1));
            f[i][j][1] = max(f[i-1][j][0] + dist(j+i-1, j),
                             f[i-1][j][1] + dist(j+i-1, j+i-2));
        }
    }
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[n][i][0]);
        ans = max(ans, f[n][i][1]);
    }
    printf("%.10f", ans); return 0;
}