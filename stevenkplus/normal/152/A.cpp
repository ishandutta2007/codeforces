#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1100;

int grid[MAXN][MAXN];
bool ssf[MAXN];
int N, M;
char buf[MAXN];
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i) {
        scanf("%s", buf);
        for(int j = 0; j < M; ++j) {
           grid[i][j] = buf[j] - '0';
       }
   }
   for(int j = 0; j < M; ++j) {
       int m = 0;
       for(int i = 0; i < N; ++i) {
           m = max(m, grid[i][j]);
       }
       for(int i = 0; i < N; ++i) {
           if (grid[i][j] == m) {
               ssf[i] = true;
           }
       }
   }
   int cnt = 0;
   for(int i = 0; i < N; ++i) {
       if (ssf[i]) cnt++;
   }
   printf("%d\n", cnt);
   return 0;
}