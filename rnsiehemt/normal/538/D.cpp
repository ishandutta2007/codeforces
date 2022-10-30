#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))

int N;
char a[55][55];
char b[115][115];
int target;
bool mark[55][55];

bool oob(int y, int x) {
    return (y < 0 || y >= N || x < 0 || x >= N);
}
bool f(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= N) return true;
    else return a[y][x] != '.';
}

void fail() { printf("NO\n"); exit(0); }

int main()
{
    scanf("%d", &N);
    for (int y = 0; y < N; y++) for (int x = 0; x < N; x++) scanf(" %c", &a[y][x]);
    for (int y = 0; y < N; y++) for (int x = 0; x < N; x++) if (a[y][x] == 'o') target++;
    for (int dy = -(N-1); dy <= N-1; dy++) for (int dx = -(N-1); dx <= N-1; dx++) {
        if (dy == 0 && dx == 0) b[52+dy][52+dx] = 'o';
        else {
            int count = 0;
            for (int y = 0; y < N; y++) for (int x = 0; x < N; x++)
                if (a[y][x] == 'o') count += f(y+dy, x+dx);
            if (count == target) b[52+dy][52+dx] = 'x';
            else b[52+dy][52+dx] = '.';
        }
    }
    for (int y = 0; y < N; y++) for (int x = 0; x < N; x++) {
        if (a[y][x] != 'o') continue;
        for (int dy = -(N-1); dy <= N-1; dy++) for (int dx = -(N-1); dx <= N-1; dx++) {
            if (b[52+dy][52+dx] == 'x' && !oob(y+dy, x+dx)) mark[y+dy][x+dx] = true;
        }
    }
    for (int y = 0; y < N; y++) for (int x = 0; x < N; x++)
        if ((a[y][x] == 'x' && !mark[y][x]) || (a[y][x] == '.' && mark[y][x])) fail();
    printf("YES\n");
    for (int dy = -(N-1); dy <= N-1; dy++) {
        for (int dx = -(N-1); dx <= N-1; dx++) 
            printf("%c", b[52+dy][52+dx]);
        printf("\n");
    }
}