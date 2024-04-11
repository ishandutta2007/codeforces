#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

char grid[55][55]; int n;
char grid2[55][55];
int status[500][500];

const char* chr = "..x";

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char s[55];
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) {
            grid[i][j] = s[j];
            grid2[i][j] = grid[i][j] == 'o' ? 'o' : '.';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] != 'o') continue;
            for (int a = -n+1; a <= n-1; a++) {
                if (i+a<1 || i+a>n) continue;
                for (int b = -n+1; b <= n-1; b++) {
                    if (j+b<1 || j+b>n) continue;
                    int new_status = 0;
                    if (grid[i+a][j+b] == '.')
                        new_status = 1;
                    status[a+100][b+100] = status[a+100][b+100] || new_status;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] != 'o') continue;
            for (int a = -n+1; a <= n-1; a++) {
                if (i+a<1 || i+a>n) continue;
                for (int b = -n+1; b <= n-1; b++) {
                    if (j+b<1 || j+b>n) continue;
                    if (grid2[i+a][j+b] == '.' && !status[a+100][b+100]) {
                        grid2[i+a][j+b] = 'x';
                    }
                }
            }
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", grid2[i][j]);
        }
        printf("\n");
    }*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] != grid2[i][j]) {
                printf("NO"); return 0;
            }
        }
    }
    printf("YES\n");
    for (int a = -n+1; a <= n-1; a++) {
        for (int b = -n+1; b <= n-1; b++) {
            if (a == 0 && b == 0) {
                printf("o"); continue;
            }
            printf("%c", status[a+100][b+100] ? '.' : 'x');
        }
        printf("\n");
    }
    return 0;
}