#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())
#define y0 y0_fedswjfwe
#define pb push_back
#define mp make_pair
#define debug(...) fprintf(stderr, __VA_ARGS__)
int n, m, inf;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int d[1100][1100][4];
char a[1100][1100];
int main () {
    #ifdef home
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        gets(a[i]);
    }
    queue<pair<pii, int> > q[2];
    memset(d, 62, sizeof(d));
    inf = d[0][0][0];
//    cerr<<inf<<endl;
    d[0][0][1] = 0;
    q[0].push(mp(mp(0, 0), 1));
    while (!q[0].empty() || !q[1].empty()) {
        for (int it = 0; it < 2; it++) {
            while (!q[it].empty()){
                pair<pii, int> v = q[it].front();
//                cerr<<v.x.x<<" "<<v.x.y<<" "<<v.y<<endl;
                q[it].pop();
                for (int i = 0; i < 4; i++) {
                    pair<pii, int> v1 = v;
                    v1.x.x += dx[i];
                    v1.x.y += dy[i];
                    v1.y = i;
                    int cs = d[v.x.x][v.x.y][v.y];
                    int ff = 0;
                    if (v1.y != v.y) {
                        cs++;
                        ff = 1;
                    }
  //                  cerr<<v1.x.x<<" "<<v1.x.y<<" "<<v1.y<<" "<<cs<<endl;
                    if (v1.x.x >= 0 && v1.x.x < n && v1.x.y >= 0 && v1.x.y < m && (v1.y == v.y || (a[v.x.x][v.x.y] == '#')) && d[v1.x.x][v1.x.y][v1.y] > cs) {
                        d[v1.x.x][v1.x.y][v1.y] = cs;
                        q[(it + ff) % 2].push(v1);
                    }
                    if (v1.x.x == n - 1 && v1.x.y == m && (v1.y == v.y || (a[v.x.x][v.x.y] == '#')) && d[v1.x.x][v1.x.y][v1.y] > cs) {
                        d[v1.x.x][v1.x.y][v1.y] = cs;
//                        q[(it + ff) % 2].push(v1);
                    }
                }
            }
        }
    }
    if (d[n - 1][m][1] == inf)
        printf("-1\n");
    else {
        printf("%d\n", d[n - 1][m][1]);
    }
    return 0;
}