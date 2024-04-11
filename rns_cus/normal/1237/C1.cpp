#include <bits/stdc++.h>
using namespace std;

#define N 200200

struct pnt{
    int x, y, z, id;
    bool operator < (const pnt &p) const {
        if (x != p.x) return x < p.x;
        if (y != p.y) return y < p.y;
        return z < p.z;
    }
    void in(int i) {
        scanf("%d %d %d", &x, &y, &z);
        id = i;
    }
    int calc(int c) {
        if (c == 0) return x + y + z;
        if (c == 1) return x + y - z;
        if (c == 2) return x - y + z;
        if (c == 3) return x - y - z;
    }

} p[N];

int n;
bool vis[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) p[i].in(i);
    sort(p + 1, p + n + 1);
    vector <pnt> vec;
    for (int i = 1, j = 1; i <= n; i = j) {
        vector <pnt> v1, v2;
        while (j <= n && p[j].x == p[i].x) v1.push_back(p[j]), j ++;
        int sz = v1.size();
        for (int k = 0; k < sz; k ++) {
            if (v2.empty() || v2.back().y != v1[k].y) v2.push_back(v1[k]);
            else {
                printf("%d %d\n", v2.back().id, v1[k].id);
                v2.pop_back();
            }
        }
        sz = v2.size();
        while (sz > 1) {
            int k = v2.back().id;
            v2.pop_back();
            int l = v2.back().id;
            v2.pop_back();
            sz -= 2;
            printf("%d %d\n", k, l);
        }
        if (sz) vec.push_back(v2[0]);
    }
    int sz = vec.size();
    assert(sz % 2 == 0);
    for (int i = 0; i < sz; i += 2) printf("%d %d\n", vec[i].id, vec[i+1].id);
}