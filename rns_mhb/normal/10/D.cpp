#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define x first
#define y second

#define N 510
int a[N], b[N], len[N][N], mxl, n, m;
pair <int, int> prv[N][N], ps;
vector <int> v[N];
stack <int> st;

void format() {
    int i, j;
    for(i = 0; i <= n; i ++) for(j = 0; j <= m; j ++) prv[i][j] = mp(0, 0), len[i][j] = 0;
    mxl = 0; ps = mp(0, 0);
}

int main() {
    int i, j, k, l, s, t;
    for(scanf("%d", &n), i = 1; i <= n; i ++) scanf("%d", a + i);
    for(scanf("%d", &m), i = 1; i <= m; i ++) scanf("%d", b + i);
    format();
    for(i = 1; i <= n; i ++) for(j = 1; j <= m; j ++) if(a[i] == b[j]) v[i].push_back(j);
    for(i = 1; i <= n; i ++) for(j = 0; j < v[i].size(); j ++) len[i][v[i][j]] = 1;
    for(i = 1; i <= n; i ++) for(j = 0; j < v[i].size(); j ++) {
        s = v[i][j];
        for(k = i + 1; k <= n; k ++) if(a[k] > a[i]) {
            for(l = 0; l < v[k].size(); l ++) {
                t = v[k][l];
                if(s < t) if(len[k][t] < len[i][s] + 1) len[k][t] = len[i][s] + 1, prv[k][t] = mp(i, s);
            }
        }
    }
    for(k = 0; k <= n; k ++) for(t = 0; t <= m; t ++) if(len[k][t] > mxl) mxl = len[k][t], ps = mp(k, t);
    printf("%d\n", mxl);
    while(ps.x + ps.y > 0) {
        st.push(a[ps.x]);
        ps = prv[ps.x][ps.y];
    }
    if(!st.empty()) printf("%d", st.top()), st.pop();
    while(!st.empty()) printf(" %d", st.top()), st.pop(); puts("");
}