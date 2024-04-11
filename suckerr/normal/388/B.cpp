#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1111;
const int INF = 1000000000;
const int DIS = 15;

int mat[N][N];
int k;
int tot;

int add(int x, int y) {
    mat[x][y] = mat[y][x] = 1;
}

void make(int times, int length, int pl) {
    int now = tot + times + 1;
    for(int i = 0; i < times; i++) {
        add(1, ++tot);
        add(tot, now);
    }
    tot = now;
    
    for(int i = 1; i <= pl; i++) {
        int nxt = now + 5;
        for(int j = 0; j < 4; j++) {
            add(now, ++tot);
            add(tot, nxt);
        }
        tot = now = nxt;
    }
    
    for(int i = pl + 1; i <= length; i++) {
        add(now, ++tot);
        now = tot;
        add(now, ++tot);
        now = tot;
    }
    
    add(now, 2);
}

int main() {
    scanf("%d", &k);
    tot = 2;
    
    for(int i = 0; i < 15; i++) {
        int a = (k >> (2 * i) & 1);
        int b = (k >> (2 * i + 1) & 1);
        int t = b * 2 + a;
        if (t)
            make(t, DIS, i);
    }
    
    
    printf("%d\n", tot);
    for(int i = 1; i <= tot; i++) {
        for(int j = 1; j <= tot; j++) {
            printf("%c", mat[i][j] ? 'Y' : 'N');
        }
        printf("\n");
    }
    return 0;
}