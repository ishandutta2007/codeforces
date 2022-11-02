#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

const int inf = (int)1e9;
const int maxk = 1001;

int g[70][70], dist[70][70];
int d[maxk + 10][70][70];

int main(){
    //freopen("chess.in", "r", stdin);
    //freopen("chess.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cout << (sizeof(g) + sizeof(dist) + sizeof(d)) / 1024 / 1024 << endl;
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int z = 0; z < n; z++){
                scanf("%d", &g[j][z]);
            }
        }
        for(int j = 0; j < n; j++){
            for(int z = 0; z < n; z++){
                for(int h = 0; h < n; h++){
                    g[z][h] = min(g[z][h], g[z][j] + g[j][h]);
                }
            }
        }
        for(int j = 0; j < n; j++){
            for(int z = 0; z < n; z++){
                dist[j][z] = min(dist[j][z], g[j][z]);
            }
        }
    }
    for(int i = 0; i <= maxk; i++){
        for(int j = 0; j < n; j++){
            for(int z = 0; z < n; z++){
                d[i][j][z] = inf;
            }
        }
    }
    for(int i = 0; i < n; i++){
        d[0][i][i] = 0;
    }
    for(int i = 0; i < maxk; i++){
        for(int j = 0; j < n; j++){
            for(int z = 0; z < n; z++){
                if(d[i][j][z] == inf){
                    continue;
                }
                for(int h = 0; h < n; h++){
                    d[i + 1][j][h] = min(d[i + 1][j][h], d[i][j][z] + dist[z][h]);
                }
            }
        }
    }
    for(int i = 0; i < r; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        int ans = inf;
        for(int j = 1; j <= c + 1; j++){
            ans = min(ans, d[j][a][b]);
        }
        printf("%d\n", ans);
    }
    return 0;
}