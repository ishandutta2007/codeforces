#include <bits/stdc++.h>
using namespace std;
#define N 55

int n, a[3], as, p[3], sc[N], pg[N], mg[N], id[N];
char s[105], ss[105];
string t[N], tt[N];

map <string, int> h;

bool cmp(int x, int y) {
    if (sc[x] != sc[y]) return sc[x] > sc[y];
    else if (pg[x] - mg[x] != pg[y] - mg[y]) return pg[x] - mg[x] > pg[y] - mg[y];
    return pg[x] > pg[y];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s);
        t[i] = s;
        h[s] = i; id[i] = i;
    }
    int m = n * (n - 1) / 2;
    while (m --) {
		scanf("%s", s);
        as = 0;
        for (char *t = strtok(s, "-"); t; t = strtok(NULL, "-")) {
            strcpy(ss, t);
			a[as ++] = h[ss];
        }
        scanf("%d:%d", &p[0], &p[1]);
        if (p[0] == p[1]) sc[a[0]] ++, sc[a[1]] ++;
        else if (p[0] > p[1]) sc[a[0]] += 3;
        else sc[a[1]] += 3;
        pg[a[0]] += p[0]; pg[a[1]] += p[1];
        mg[a[0]] += p[1]; mg[a[1]] += p[0];
    }
    sort(id + 1, id + n + 1, cmp);
    for (int i = 1; i <= n / 2; i ++) tt[i] = t[id[i]];
    sort(tt + 1, tt + n / 2 + 1);
    for (int i = 1; i <= n / 2; i ++) cout << tt[i] << endl;
}