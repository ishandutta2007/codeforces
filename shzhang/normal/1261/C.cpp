#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <set>
#include <queue>

using namespace std;

#define ll long long

#define encode(i, j) ((i) == 0 || (j) == 0 ? 0 : (((i)-1)*m+(j)))

int n, m;
bool burnt[1000005];
int psum[1000005];
char s[1000005];
bool tmp[1000005]; bool tmp2[1000005];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool check(int t)
{
    queue<pair<int, int> > bfs;
    for (int i = 1; i <= n * m; i++) tmp[i] = tmp2[i] = false;
    for (int i = t + 1; i <= n - t; i++) {
        for (int j = t + 1; j <= m - t; j++) {
            int total = psum[encode(i+t, j+t)] - psum[encode(i-t-1, j+t)]
                - psum[encode(i+t, j-t-1)] + psum[encode(i-t-1, j-t-1)];
            //printf("%d %d %d %d: %d\n", t, i, j, encode(i, j), total);
            if (total == (2 * t + 1) * (2 * t + 1)) {
                tmp[encode(i, j)] = tmp2[encode(i, j)] = true; bfs.push(make_pair(i, j));
                //printf("YES");
            }
        }
    }
    /*printf("%d\n", t);
    for (int i = 1; i <= n * m; i++) {
        printf("%c", tmp[i] ? 'X' : '.');
        if (i % m == 0) printf("\n");
    }*/
    for (int i = 1; i <= t; i++) {
        int quelen = bfs.size();
        for (int j = 1; j <= quelen; j++) {
            pair<int, int> pos = bfs.front();
            bfs.pop();
            for (int k = 0; k < 8; k++) {
                pair<int, int> newpos = pos;
                newpos.first += dx[k];
                newpos.second += dy[k];
                if (!newpos.first || !newpos.second || newpos.first > n || newpos.second > m) continue;
                if (tmp[encode(newpos.first, newpos.second)]) continue;
                tmp[encode(newpos.first, newpos.second)] = true;
                bfs.push(newpos);
            }
        }
    }
    /*printf("%d\n", t);
    for (int i = 1; i <= n * m; i++) {
        printf("%c", tmp[i] ? 'X' : '.');
        if (i % m == 0) printf("\n");
    }*/
    for (int i = 1; i <= n * m; i++) {
        if (tmp[i] != burnt[i]) return false;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            burnt[encode(i, j)] = (s[j] == 'X');
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            psum[encode(i, j)] = psum[encode(i, j-1)] +
                psum[encode(i-1, j)] - psum[encode(i-1, j-1)] +
                (burnt[encode(i, j)] ? 1 : 0);
        }
    }
    //for (int i = 1; i <= n * m; i++) printf("%d ", psum[i]);
    int l = 0, r = min(n, m);
    while (l < r) {
        int mid = (l + r) / 2 + 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    check(l);
    printf("%d\n", l);
    for (int i = 1; i <= n * m; i++) {
        printf("%c", tmp2[i] ? 'X' : '.');
        if (i % m == 0) printf("\n");
    }
    return 0;
}