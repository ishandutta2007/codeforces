#include <bits/stdc++.h>
using namespace std;

#define N 111

int n, m, pos[N];

int query(int p, int d) {
    printf("? %d %d\n", p, d);
    fflush(stdout);
    int rlt;
    scanf("%d", &rlt);
    return rlt;
}


int main() {
    scanf("%d %d", &n, &m);

    vector <int> vec;
    for (int i = 1; i < n; i ++) vec.push_back(i);

    int currot = 1;
    int curcnt = query(0, 1);

    while (!vec.empty()) {
        curcnt = query(0, -1), currot --;
        while (1) {
            currot ++;
            int tmp = query(0, 1);
            swap(curcnt, tmp);
            if (tmp < curcnt) break;
        }
        while (1) {
            int tmp = query(0, 1);
            if (tmp <= curcnt) {
                query(0, -1);
                break;
            }
            else curcnt = tmp, currot ++;
        }

        vector <int> tar = vec;
        int dir = -1;
        while (1) {
            int sz = tar.size();
            if (sz == 1) {
                int x = tar[0];
                if (dir == -1) {
                    pos[x] = currot - m - 1;
                    for (int i = 0; i <= m; i ++) curcnt = query(x, -1);
                }
                else {
                    pos[x] = currot - 1 - m;
                    for (int i = 0; i < m; i ++) curcnt = query(x, -1);
                }
                tar.clear();
                for (auto y : vec) if (x != y) tar.push_back(y);
                swap(tar, vec);
                break;
            }
            int hsz = sz >> 1;
            for (int i = 0; i < hsz; i ++) query(tar[i], dir);
            curcnt = query(0, -1);
            int tmp = query(0, 1);
            vector <int> oth;
            if (tmp > curcnt) {
                if (dir == -1) for (int i = hsz; i < sz; i ++) oth.push_back(tar[i]);
                else for (int i = 0; i < hsz; i ++) oth.push_back(tar[i]);
                dir = -1;
            }
            else {
                if (dir == -1) for (int i = 0; i < hsz; i ++) oth.push_back(tar[i]);
                else for (int i = hsz; i < sz; i ++) oth.push_back(tar[i]);
                dir = 1;
            }

            swap(oth, tar);
        }

    }
    putchar('!');
    for (int i = 1; i < n; i ++) {
        int c = (pos[i] - currot) % (n * m);
        if (c < 0) c += n * m;
        printf(" %d", c);
    }
    puts("");
    fflush(stdout);

    return 0;
}