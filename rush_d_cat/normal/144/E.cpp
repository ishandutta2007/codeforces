#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
const int NICO = 100000 + 10;
struct Num {
    int r, c, id;
    int l;
} a[NICO];
bool cmp(Num x, Num y) {
    if(x.l == y.l) return x.r < y.r;
    return x.l < y.l;
}
struct cmp1 {
    bool operator ()(Num &a, Num &b) {
        return a.r > b.r;
    }
};
vector<int> res;
priority_queue<Num, vector<Num>, cmp1> que;
int vis[NICO], n, m;

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;i++) {
        scanf("%d %d", &a[i].r, &a[i].c);
        a[i].l = n + 1 - a[i].c;
        a[i].id = i; 
    }
    sort(a + 1, a + 1 + m, cmp);

    int cnt = 0, pos = 1;
    for(int i = 1; i <= n; ++ i) {
        while(pos <= m && a[pos].l <= i) {
            que.push(a[pos]);
            pos ++;
        }

        if(que.size()) {
            vis[i] = que.top().id; que.pop();
            cnt ++;
        }

        while(que.size()) {
            Num x = que.top();
            if(x.r == i) {
                que.pop();
            } else {
                break;
            }
        }
    }

    printf("%d\n", cnt);
    for(int i = 1; i <= n; i ++) {
        if(vis[i]) {
            printf("%d ", vis[i]);
        }
    }

}