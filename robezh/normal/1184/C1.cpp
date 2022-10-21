#include <bits/stdc++.h>
using namespace std;

const int N = 45, INF = (int)1e9;

struct P {
    int x, y;
};

int n;
int x[N], y[N];
map<int, int> mp;

bool check(vector<P> v) {
    int cnt[4] = {0, 0, 0, 0};
    int lx = INF, rx = -1, uy = -1, dy = INF;
    for(P p : v) {
        lx = min(lx, p.x);
        rx = max(rx, p.x);
        dy = min(dy, p.y);
        uy = max(uy, p.y);
    }
    for(P p : v) {
        if(p.x == lx) cnt[0]++;
        if(p.x == rx) cnt[1]++;
        if(p.y == uy) cnt[2]++;
        if(p.y == dy) cnt[3]++;
        if(p.x != lx && p.x != rx && p.y != uy && p.y != dy) return false;
    }
    return (cnt[0] >= n && cnt[1] >= n && cnt[2] >= n && cnt[3] >= n);
}

int main() {
    cin >> n;
    int m = 4 * n + 1;
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < m; i++) {
        vector<P> v;
        for(int j = 0; j < m; j++) if(i != j) v.push_back({x[j], y[j]});
        if(check(v)) {
            cout << x[i] << " " << y[i] << endl;
            return 0;
        }
    }
    assert(false);
}