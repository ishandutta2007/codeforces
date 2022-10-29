#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 111;

int n, p;
int map[N][N];

int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        scanf("%d %d", &n, &p);
        memset(map, 0, sizeof(map));
        for(int i = 1; i < n; i++) {
            map[i][i + 1] = 1;
        }
        
        for(int i = 1; i < n - 1; i++) {
            map[i][i + 2] = 1;
        }
        
        map[1][4] = map[1][5] = map[2][5] = 1;
        
        for(int i = 1; i <= n && p; i++)
            for(int j = i + 1; j <= n && p; j++) {
                if (map[i][j] == 0) {
                    map[i][j] = 1;
                    p--;
                }
            }
            
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                if (map[i][j])
                    printf("%d %d\n", i, j);
    }
    return 0;
}