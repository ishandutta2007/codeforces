#include <bits/stdc++.h>
using namespace std;

#define N 1010

int h, v, l[N], p[N];
int pa[250250];
bool vis[N];

int solve(int n, int *a) {
    int sum = 0;
    for (int i = 0; i < n; i ++) sum += a[i];
    if (sum & 1) return -1;
    sum /= 2;
    for (int i = 1; i <= sum; i ++) pa[i] = -1;
    pa[0] = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = sum - a[i]; j >= 0; j --) if (pa[j] >= 0) {
            int c = j + a[i];
            if (pa[c] < 0) pa[c] = i;
        }
    }
    if (pa[sum] < 0) return -1;
    vector <int> one, two;
    for (int i = 0; i < n; i ++) vis[i] = 0;

    while (sum > 0) {
        int c = pa[sum];
        one.push_back(a[c]);
        vis[c] = 1;
        sum -= a[c];
    }
    for (int i = 0; i < n; i ++) if (!vis[i]) two.push_back(a[i]);
    int rlt = one.size();
    for (int i = 0; i < rlt; i ++) a[i] = one[i];
    for (int i = rlt; i < n; i ++) a[i] = two[i-rlt];
    return rlt;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &v);
        for (int i = 0; i < v; i ++) scanf("%d", &p[i]);
        scanf("%d", &h);
        for (int i = 0; i < h; i ++) scanf("%d", &l[i]);
        if (h != v) {
            puts("No"); continue;
        }
        int mh = solve(h, l);
        if (mh < 0) {
            puts("No"); continue;
        }
        int mv = solve(v, p);
        if (mv < 0) {
            puts("No"); continue;
        }

        int k = 0, s = 0, t = mh;
        int cs = 0, ct = 0;
        while (k < mv - 1) {
            if (cs + l[s] < ct + l[t]) cs += l[s++];
            else ct += l[t++];
            k ++;
        }

        sort(p, p + mv, greater <int> () );
        sort(p + mv, p + v, greater <int> () );


        puts("Yes");
        assert(s + t - mh == mv - 1);
        int x = 0, y = 0;
        for (int i = 0; i < s; i ++) {
            printf("%d %d\n", x, y);
            x += p[i];
            printf("%d %d\n", x, y);
            y -= l[s-1-i];
        }
        for (int i = s; i < mv; i ++) {
            printf("%d %d\n", x, y);
            x += p[i];
            printf("%d %d\n", x, y);
            y += l[i-s+mh];
        }

        for (int i = t + 1; i < h; i ++) {
            printf("%d %d\n", x, y);
            x -= p[i-t-1+mv];
            printf("%d %d\n", x, y);
            y += l[i];
        }

        for (int i = mh - 1; i >= s; i --) {
            printf("%d %d\n", x, y);
            x -= p[v+s-1-i];
            printf("%d %d\n", x, y);
            y -= l[i];
        }
        assert(x == 0 && y == 0);

    }

    return 0;
}