#include <bits/stdc++.h>

using namespace std;

int N;
char s[100010];
typedef pair<int,int> pii;
pii fuck(char ch) {
    if (ch == 'L') return pii(-1, 0);
    if (ch == 'R') return pii(1, 0);
    if (ch == 'U') return pii(0, 1);
    if (ch == 'D') return pii(0, -1);
    assert(false);    
}

bool check(int ox, int oy) {
    int x = 0, y = 0;
    for (int i=1;i<=N;i++) {
        auto tmp = fuck(s[i]);
        int dx = tmp.first;
        int dy = tmp.second;
        if (x + dx == ox && y + dy == oy) continue;
        x += dx;
        y += dy;
    }
    return (x == 0 && y == 0);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s", s + 1);
        N = strlen(s + 1);
        int ansx = 0, ansy = 0;
        int x = 0, y = 0;
        if (check(10000, 10000)) ansx = ansy = 10000;
        for (int i=1;i<=N;i++) {
            auto tmp = fuck(s[i]);
            int dx = tmp.first;
            int dy = tmp.second;
            if (check(x + dx, y + dy)) {
                ansx = x + dx;
                ansy = y + dy;
            }
            x += dx;
            y += dy;
        }
        printf("%d %d\n",ansx,ansy);
    }    
}