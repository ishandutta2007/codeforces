#include <bits/stdc++.h>
using namespace std;
#define M 100100
const int oo = 1000000;

char a[M], b[M];
char p[M];
int con[30][30];
int n;

int solve() {
    int cost = 0;
    for (int i = 0; i < n; i++) {
        int mx = oo;
        for (int c = 0; c < 26; c++) {
            int nval = con[a[i]-'a'][c] + con[b[i]-'a'][c];
            if (mx > nval) {
                mx = nval;
                p[i] = c + 'a';
            }
        }
        if (mx == oo) {
            puts("-1");
            exit(0);
        }
        cost += mx;
    }
    p[n] = 0;
    return cost;
}

int main() {
    //freopen("B3.in", "r", stdin);
    scanf("%s %s", a, b);
    n = strlen(a);
    if (strlen(b) != n) {
        puts("-1");
        return 0;
    }

    for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) {
        if (i == j) con[i][j] = 0;
        else con[i][j] = oo;
    }

    int m;
    scanf("%d", &m);
    while (m--) {
        char s[3], t[3];
        int x;
        scanf("%s %s %d", s, t, &x);
        int i = s[0] - 'a';
        int j = t[0] - 'a';
        con[i][j] = min(con[i][j], x);
    }
    for (int k = 0; k < 26; k++) for (int i = 0; i< 26; i++) for (int j = 0; j < 26; j++) {
        con[i][j] = min(con[i][j], con[i][k] + con[k][j]);
    }


    printf("%d\n", solve());
    puts(p);

    return 0;
}