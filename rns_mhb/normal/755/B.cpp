#include <bits/stdc++.h>
using namespace std;

#define N 1005

int n, m;
int a, b, c;
map<string, bool> vis;
char s[N];
string ss;

int main() {
    scanf("%d %d ", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf("%s", s); ss = s;
        vis[ss] = 1;
    }
    for (int i = 0; i < m; i ++) {
        scanf("%s", s); ss = s;
        if (vis.count(ss)) a ++;
    }
    b = n - a, c = m - a;
    if ((a & 1) && b >= c || !(a & 1) && b >= c + 1) printf("YES\n");
    else printf("NO\n");
}