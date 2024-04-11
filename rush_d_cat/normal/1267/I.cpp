#include <bits/stdc++.h>
using namespace std;

int t, n;
int f[202][202];

int ask(int u, int v) {
    if (f[u][v] != -1) {
        return f[u][v];
    }
    printf("? %d %d\n", u, v);
    fflush(stdout);
    char s[2];
    scanf("%s", s);
    return f[u][v] = ((s[0] == '<') ? 0 : 1);
}

vector<int> v1, v2;

bool cmp(int x, int y) {
    return ask(x, y) == 1;
}

int main() {
    scanf("%d", &t);
    while (t --) {
        memset(f, -1, sizeof(f));
        scanf("%d", &n);
        v1.clear(); v2.clear();
        v1.push_back(1); v1.push_back(2);
        for (int i = 3; i < 3 + n-1; i ++) {
            v2.push_back(i);
        }
        sort(v1.begin(), v1.end(), cmp);
        sort(v2.begin(), v2.end(), cmp);
        for (int i = n + 2; i <= 2 * n; i ++) {
            if (ask(v1.back(), v2.back()) == false) {
                v1.pop_back();
                v1.push_back(i);
                sort(v1.begin(), v1.end(), cmp);
            } else {
                v2.pop_back();
                v2.push_back(i);
                sort(v2.begin(), v2.end(), cmp);
            }
        }

        ask(v1.back(), v2.back());
        printf("!\n"); fflush(stdout);
    }
}