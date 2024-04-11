#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int n, m;
char matr[32][32];
int cl[32][32];

int ck;
int cx[1024], cy[1024];

int temp;
int ans;

int best[140];

int k;
int arr[140];
int cnt[70];
int used[70][70];
void Solve(int u) {
        if (u == 14) {
                temp++;
                memset(used, 0, sizeof(used));
                for (int i = 0; i<n; i++)
                        for (int j = 0; j<m; j++) if (matr[i][j] != '.') {
                                for (int d = 0; d<4; d++) {
                                        int ni = i + dir[d][0];
                                        int nj = j + dir[d][1];
                                        if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                                        if (matr[i][j] == matr[ni][nj]) {
                                                int a = arr[cl[i][j]];
                                                int b = arr[cl[ni][nj]];
                                                if (a > b) swap(a, b);
                                                used[a][b]++;
                                                if (used[a][b] > 2) return;
                                                break;
                                        }
                                }
                        }
                if (ans == 0) memcpy(best, arr, sizeof(best));
                ans++;
                return;
        }
        for (int i = 0; i<=k; i++) if (cnt[i] < 2) {
                bool inck = (i == k);
                if (inck && k == 7) continue;

                arr[u] = i;
                if (inck) k++;
                cnt[i]++;
                Solve(u+1);
                cnt[i]--;
                if (inck) k--;
                arr[u] = -1;
        }
}

int main() {
#ifdef HOME
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif  
        scanf("%d%d", &n, &m);
        for (int i = 0; i<n; i++) scanf("%s", matr[i]);

        memset(cl, -1, sizeof(cl));
        for (int i = 0; i<n; i++)
                for (int j = 0; j<m; j++) if (matr[i][j] != '.' && cl[i][j] < 0) {
                        cl[i][j] = ck;
                        cl[i+1][j] = ck;
                        cl[i][j+1] = ck;
                        cl[i+1][j+1] = ck;
                        cx[ck] = i;
                        cy[ck] = j;
                        ck++;
                }

        memset(arr, -1, sizeof(arr));
        k = 0;
        Solve(0);

//      printf("%d / %d\n", ans, temp);

        printf("%d\n", ans * 5040);
        for (int i = 0; i<n; i++) {
                for (int j = 0; j<m; j++) {
                        if (matr[i][j] == '.') printf(".");
                        else {
                                char c = '0' + best[cl[i][j]];
                                printf("%c", c);
                        }
                }
                printf("\n");
        }
    
        return 0;
}