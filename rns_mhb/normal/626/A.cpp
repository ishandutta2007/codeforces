#include <bits/stdc++.h>
using namespace std;

int n, x, y;
char ch;
typedef pair<int, int> pii;
map<pii, int> vis;
map<pii, int> :: iterator it;

int main() {
    scanf("%d ", &n);
    vis[pii(x, y)] ++;
    while (n --) {
        ch = getchar();
        if (ch == 'U') y ++;
        else if (ch == 'D') y --;
        else if (ch == 'L') x --;
        else x ++;
        vis[pii(x, y)] ++;
    }
    int ans = 0;
    for (it = vis.begin(); it != vis.end(); it ++) {
        int x = it -> second;
        ans += x * (x - 1) / 2;
    }
    printf("%d\n", ans);
}