#include <iostream>
#include <vector>
using namespace std;
const int NICO = 1000000+10;
int n, m, dx, dy;
int x[NICO], y[NICO];

vector<int> apple[NICO];
int head[NICO];
int cnt[NICO];

void debug() {
    for(int i=0;i<n;i++) {
        printf("head[%d] = %d\n", i, head[i]);
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &dx, &dy);
    for(int i=1;i<=m;i++) {
        scanf("%d %d", &x[i], &y[i]);
        apple[x[i]].push_back(y[i]);
    }

    int cx = 0, cy = 0; head[0] = 0;
    for(int i=1;i<n;i++) {
        head[(cx + dx) % n] = (cy + dy) % n;
        cx = (cx + dx) % n; cy = (cy + dy) % n;
    }

    int ans = 0, mx = -1;

    for(int row=0;row<n;row++) {
        for(int i=0;i<apple[row].size();i++) {
            if(head[row] <= apple[row][i]) cnt[apple[row][i] - head[row]] ++;
            else cnt[apple[row][i] - head[row] + n] ++;
        }
    }

    for(int i=0;i<n;i++) {
        if(cnt[i] > mx) {
            mx = cnt[i];
            ans = i;
        }
    }
    printf("%d %d\n", 0, ans);

}