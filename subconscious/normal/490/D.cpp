#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
typedef long long LL;
#define N 1000010

int a[2], b[2];
map<LL, int> res[2];
map<LL, pair<int, int> > way[2];
map<LL, int>::iterator it1, it2;
struct node {
    int x, y;
} f1, f2;
queue<node> q;
int ans;
LL fzc;

int main() {
    LL u, v;
    int now;
    scanf("%d%d%d%d", &a[0], &b[0], &a[1], &b[1]);
    res[0][(LL) (a[0]) * b[0]] = 0;
    res[1][(LL) (a[1]) * b[1]] = 0;
    way[0][(LL) (a[0]) * b[0]] = make_pair(a[0], b[0]);
    way[1][(LL) (a[1]) * b[1]] = make_pair(a[1], b[1]);
    for (int i = 0; i <= 1; i++) {
        f1.x = a[i];
        f1.y = b[i];
        q.push(f1);
        while (!q.empty()) {
            f1 = q.front();
            u = (LL) (f1.x) * f1.y;
            q.pop();
            now = res[i][u];
            if (u % 2 == 0) {
                v = u / 2;
                if (!res[i].count(v)) {
                    res[i][v] = now + 1;
                    if (f1.x % 2 == 0) {
                        f2.x = f1.x / 2;
                        f2.y = f1.y;
                    } else {
                        f2.x = f1.x;
                        f2.y = f1.y / 2;
                    }
                    way[i][v] = make_pair(f2.x, f2.y);
                    q.push(f2);
                }
            }
            if (u % 3 == 0) {
                v = u / 3 * 2;
                if (!res[i].count(v)) {
                    res[i][v] = now + 1;
                    if (f1.x % 3 == 0) {
                        f2.x = f1.x / 3 * 2;
                        f2.y = f1.y;
                    } else {
                        f2.x = f1.x;
                        f2.y = f1.y / 3 * 2;
                    }
                    way[i][v] = make_pair(f2.x, f2.y);
                    q.push(f2);
                }
            }
        }
    }
    ans = -1;
    for (it1 = res[0].begin(), it2 = res[1].begin();
            it1 != res[0].end() && it2 != res[1].end();) {
        if ((*it1).first == (*it2).first) {
            if (ans == -1 || (*it1).second + (*it2).second < ans) {
                ans = (*it1).second + (*it2).second;
                fzc = (*it1).first;
            }
            it1++;
            it2++;
        } else if ((*it1).first > (*it2).first)
            it2++;
        else
            it1++;
    }
    printf("%d\n", ans);
    if (ans >= 0) {
        pair<int, int> tp1 = way[0][fzc], tp2 = way[1][fzc];
        printf("%d %d\n", tp1.first, tp1.second);
        printf("%d %d\n", tp2.first, tp2.second);
    }
    return 0;
}