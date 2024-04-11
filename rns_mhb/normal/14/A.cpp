#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[110][110];

int main() {
    int p1, p2, q1, q2;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++) scanf("%s", s[i]);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(s[i][j] == '*') {
                p2 = i;
                break;
            }
        }
    }
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            if(s[j][i] == '*') {
                q2 = i;
                break;
            }
        }
    }
    for(int i = n - 1; i >= 0; i --) {
        for(int j = 0; j < m; j ++) {
            if(s[i][j] == '*') {
                p1 = i;
                break;
            }
        }
    }
    for(int i = m - 1; i >= 0; i --) {
        for(int j = 0; j < n; j ++) {
            if(s[j][i] == '*') {
                q1 = i;
                break;
            }
        }
    }
    for(int i = p1; i <= p2; i ++) {
        for(int j = q1; j <= q2; j ++) printf("%c", s[i][j]);
        puts("");
    }
}