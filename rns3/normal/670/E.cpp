#include <bits/stdc++.h>
using namespace std;

int n, m, p;
const int M = 1000001;

char s[M], ss[M];
int match[M], bef[M], nxt[M];
pair<int, int> A[M];
int cnt;
int vis[M];

int main() {
    scanf("%d %d %d", &n, &m, &p);
    scanf("%s", s + 1);
    for(int i = 0; i <= n; i ++) nxt[i] = i + 1;
    for(int i = 0; i <= n; i ++) bef[i] = i - 1;
    int start = 1;
    while(start <= n) {
        if(bef[start] > 0 && s[bef[start]] == '(' && s[start] == ')') {

            match[bef[start]] = start;
            match[start] = bef[start];
            int x = bef[bef[start]], y = nxt[start];
            bef[y] = x;
            nxt[x] = y;
            start = y;
        }
        else start = nxt[start];
    }
    scanf("%s", ss + 1);
    start = p;
    for(int i = 0; i <= n; i ++) nxt[i] = i + 1;
    for(int i = 0; i <= n; i ++) bef[i] = i - 1;
    for(int i = 1; i <= m; i ++){
        assert(start > 0 && start <= n);
        if(ss[i]  == 'R') {
            start = nxt[start];
        }
        else if(ss[i] == 'L') {
            start = bef[start];
        }
        else {
            int x = match[start], y = start;
            if(x > y) swap(x, y);
            A[cnt ++] = make_pair(x, y);
            int xx = bef[x], yy = nxt[y];
            nxt[xx] = yy;
            bef[yy] = xx;
            if(yy > n) {
                start = xx;
            }
            else start = yy;
        }
    }
    sort(A, A + cnt);
    int h = 0;
    for(int i = 0; i < cnt; i ++){
        int x = A[i].first, y  = A[i].second;
        for(int j = max(x, h+1); j <= y; j ++) vis[j] = 1;
        h = max(h, y);
    }
    for(int i = 1; i <= n; i ++) if(!vis[i]) printf("%c",s[i]);
}