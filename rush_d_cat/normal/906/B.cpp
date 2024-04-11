#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

int n, m;
vector<int> black, white;

bool is_link(int x, int y) {
    int px1 = (x + m-1) / m, py1 = x % m; if (py1 == 0) py1 = m;
    int px2 = (y + m-1) / m, py2 = y % m; if (py2 == 0) py2 = m;
    if (px1 == px2 && abs(py1 - py2) == 1)  return 1;
    if (py1 == py2 && abs(px1 - px2) == 1)  return 1;
    return 0;
}

void naive() {
    int ans[5][5];
    vector<int> vec;
    for (int i = 1; i <= n*m; i ++) {
        vec.push_back(i);
    }
    for (int test = 1; test <= 1000000; test ++) {
        std::random_shuffle(vec.begin(), vec.end());
        int c = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                ans[i][j] = vec[c ++];
            }
        }

        bool can = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (i < n && is_link(ans[i][j], ans[i+1][j]))
                    can = 0;

                if (j < m && is_link(ans[i][j], ans[i][j+1]))
                    can = 0;
            }
        }
        if (can) {
            printf("YES\n");
            for (int i = 1; i <= n; i ++) {
                for (int j = 1; j <= m; j ++) {
                    printf("%d ", ans[i][j]);
                }
                printf("\n");
            }
            return;
        }
    }
    printf("NO\n");
}

int main() {
    cin >> n >> m;

    if (n <= 3 && m <= 3) {
        naive();
        return 0;
    }

    if (n == 1) {
        printf("YES\n");
        for (int i = 1; i <= m/2; i ++) {
            printf("%d ", 2*i);
        }
        for (int i = 1; i <= (m+1)/2; i ++) {
            printf("%d ", 2*i-1);
        }
        return 0;
    }


    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {           
            if ((i+j)%2 == 0) 
                black.push_back((i-1)*m + j);
            else 
                white.push_back((i-1)*m + j);      
        }
    }

    
    int mp[n+2][m+2];
    memset(mp, 0, sizeof(mp));
    bool ok = 0;

    for (int test = 1; test <= 100; test ++) {
        //printf("test %d\n", test);
        std::random_shuffle(white.begin(), white.end());
        std::random_shuffle(black.begin(), black.end());     
        bool valid = 1;
        if (n % 2 == 0) {

            for (int i = 0; i < m; i ++) {
                if (is_link(white[i], black[i])) {
                    valid = 0; break;
                }
            }

            if (valid) {
                ok = 1;
                for (int i = 0; i < m; i ++) {
                    mp[n/2][i+1] = white[i]; 
                    mp[n/2+1][i+1] = black[i]; 
                }
                /*
                for (int i = 1; i <= n; i ++) {
                    for (int j = 1; j <= m; j ++) {
                        printf("%d ", mp[i][j]);
                    }
                    printf("\n");
                }
                */
                break;
            }

        } else {

            for (int i = 0; i < m; i ++) {
                if (is_link(white[i], black[i])) {
                    valid = 0; break;
                }
            }

            if (is_link(white[m/2-1], black[m/2]))
                valid = 0;

            if (valid) {
                ok = 1;
                for (int i = 0; i < m; i ++) {
                    mp[(i<m/2) ? ((n+1)/2) : ((n+1)/2-1)][i+1] = white[i]; 
                    mp[(i<m/2) ? ((n+1)/2+1) : ((n+1)/2)][i+1] = black[i]; 
                }
                break;
            }

        }

    }
    /*
    if (ok) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                printf("%d\t", mp[i][j]);
            }
            printf("\n");
        }        
        return 0;
    }
    */
    
    if (!ok) {
        printf("NO\n");
        return 0;
    }

    int cur_white = m, cur_black = m;
    for (int i = 1; i <= n*m; i ++) {
        int r = (i + m-1) / m;
        int c = i % m; if (c == 0) c = m;
        if (mp[r][c]) continue;

        if (cur_white < white.size())
            mp[r][c] = white[cur_white ++];
        else
            mp[r][c] = black[cur_black ++];
    }

    printf("YES\n");
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            printf("%d ", mp[i][j]);
        }
        printf("\n");
    }

}