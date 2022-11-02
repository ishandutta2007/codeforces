#include <bits/stdc++.h>
typedef long long ll;
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
#define mod(x) ((x)%Mod)

int Q, qx[200005], qy[200005];
char qd[200005];
int max[2][123*200*1000+5], N[2];
std::vector<int> x, y;

void update(int s, int n, int nl, int nr, int ul, int ur, int uv) {
    if (ur <= nl || nr <= ul) return;
    else if (ul <= nl && nr <= ur) domax(max[s][n], uv);
    else {
        update(s, n*2+1, nl, (nl+nr)/2, ul, ur, uv);
        update(s, n*2+2, (nl+nr)/2, nr, ul, ur, uv);
    }
}
int query(int s, int n, int nl, int nr, int qi) {
    if (nl+1 == nr) return max[s][n];
    else if (qi < (nl+nr)/2) return std::max(max[s][n], query(s, n*2+1, nl, (nl+nr)/2, qi));
    else return std::max(max[s][n], query(s, n*2+2, (nl+nr)/2, nr, qi));
}

int cx(int a) { return std::lower_bound(x.begin(), x.end(), a) - x.begin(); }
int cy(int a) { return std::lower_bound(y.begin(), y.end(), a) - y.begin(); }

int main()
{
    N[0] = N[1] = 1;
    scanf("%*d%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d%d %c", &qx[i], &qy[i], &qd[i]);
        x.push_back(qx[i]);
        y.push_back(qy[i]);
    }
    x.push_back(0); y.push_back(0);
    std::sort(x.begin(), x.end());
    x.erase(std::unique(x.begin(), x.end()), x.end());
    std::sort(y.begin(), y.end());
    y.erase(std::unique(y.begin(), y.end()), y.end());
    for (int i = 0; i < Q; i++) {
        int xx = cx(qx[i]), yy = cy(qy[i]);
        if (qd[i] == 'U') {
            //printf("query x %d %d\n", xx, query(0, 0, 0, 200003, xx));
            int q = query(0, 0, 0, 200003, xx);
            printf("%d\n", qy[i] - y[q]);
            //printf("update %d %d with %d\n", xx, xx+1, yy);
            update(0, 0, 0, 200003, xx, xx+1, yy);
            update(1, 0, 0, 200003, q+1, yy+1, xx);
        } else {
            //printf("query y %d %d\n", yy, query(1, 0, 0, 200003, yy));
            int q = query(1, 0, 0, 200003, yy);
            printf("%d\n", qx[i] - x[q]);
            //printf("update %d %d with %d\n", yy, yy+1, xx);
            update(1, 0, 0, 200003, yy, yy+1, xx);
            update(0, 0, 0, 200003, q+1, xx+1, yy);
        }
    }
}