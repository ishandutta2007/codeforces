#include <bits/stdc++.h>

using namespace std;



#define gc getchar

#define pc putchar



inline char nc(){

  static char buf[100000],*p1=buf,*p2=buf;

  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }

  return *p1++;

}



inline int getint(){

  int x;

  char c=nc(),b=1;

  if(c == -1)

    return 0;

  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;

  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;

  return x;

}



inline void putint(int x) {

  static int a[11], i; i = 0;

  if (x < 0) pc('-'), x = -x;

  do { a[i ++] = x % 10 ^ 48; x /= 10; } while (x);

  while (i) pc(a[--i]);

}



#define pb push_back

#define x first

#define y second



template <class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

const int inf = 1e9;

const ll linf = 1e18;

const int mod = 1e9 + 7;

const double eps = 1e-7;



#define N 105



//const int inf = 1e9;



struct hangarian {

    int n, cost[N][N], max_match;

    int lx[N], ly[N], xy[N], yx[N];

    bool S[N], T[N];

    int slack[N], slackx[N], prv[N], q[N];



    void init_labels() {

        memset(lx, 0, sizeof lx);

        memset(ly, 0, sizeof ly);

        for (int x = 0; x < n; x ++) {

            for (int y = 0; y < n; y ++) lx[x] = max(lx[x], cost[x][y]);

        }

    }



    void update_labels() {

        int x, y, delta = inf;

        for (y = 0; y < n; y ++) if (!T[y]) delta = min(delta, slack[y]);

        for (x = 0; x < n; x ++) if (S[x]) lx[x] -= delta;

        for (y = 0; y < n; y ++) {

            if (T[y]) ly[y] += delta;

            else slack[y] -= delta;

        }

    }



    void add_to_tree(int x, int prvx) {

        S[x] = 1;

        prv[x] = prvx;

        for (int y = 0; y < n; y ++) {

            if (lx[x] + ly[y] - cost[x][y] < slack[y]) {

                slack[y] = lx[x] + ly[y] - cost[x][y];

                slackx[y] = x;

            }

        }

    }



    void augment() {

        if (max_match == n) return;

        int x, y, root;

        int wr = 0, rd = 0;



        memset(S, 0, sizeof S);

        memset(T, 0, sizeof T);

        memset(prv, -1, sizeof prv);

        for (x = 0; x < n; x ++) if (xy[x] == -1) break;

        q[wr++] = root = x;

        prv[x] = -2;

        S[x] = 1;

        for (y = 0; y < n; y ++) {

            slack[y] = lx[root] + ly[y] - cost[root][y];

            slackx[y] = root;

        }



        while (1) {

            while (rd < wr) {

                x = q[rd++];

                for (y = 0; y < n; y ++) {

                    if (cost[x][y] == lx[x] + ly[y] && !T[y]) {

                        if (yx[y] == -1) break;

                        T[y] = 1;

                        q[wr++] = yx[y];

                        add_to_tree(yx[y], x);

                    }

                }

                if (y < n) break;

            }

            if (y < n) break;

            update_labels();

            wr = rd = 0;

            for (y = 0; y < n; y ++) {

                if (!T[y] && !slack[y]) {

                    if (yx[y] == -1) {

                        x = slackx[y]; break;

                    }

                    else {

                        T[y] = 1;

                        if (!S[yx[y]]) {

                            q[wr++] = yx[y];

                            add_to_tree(yx[y], slackx[y]);

                        }

                    }

                }

            }

            if (y < n) break;

        }



        if (y < n) {

            max_match ++;

            for (int cx = x, cy = y, ty; cx != -2; cx = prv[cx], cy = ty) {

                ty = xy[cx];

                yx[cy] = cx;

                xy[cx] = cy;

            }

            augment();

        }

    }



    int solve(int _n) {

        n = _n;

        max_match = 0;

        memset(xy, -1, sizeof xy);

        memset(yx, -1, sizeof yx);

        init_labels();

        augment();

        int rlt = 0;

        for (int x = 0; x < n; x ++) rlt += cost[x][xy[x]];

        return rlt;

    }

} hang;



int n;

string s[N], t[N];

char tmp[N];



int dist(int i, int j) {

    if (s[i].size() != t[j].size()) return -inf;

    int rtn = 0;

    for (int k = 0; k < s[i].size(); k ++) {

        if (s[i][k] != t[j][k]) rtn ++;

    }

    return -rtn;

}



int main() {

    scanf("%d ", &n);

    for (int i = 0; i < n; i ++) {

        gets(tmp);

        s[i] = tmp;

    }

    for (int i = 0; i < n; i ++) {

        gets(tmp);

        t[i] = tmp;

    }

    for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) hang.cost[i][j] = dist(i, j);

    printf("%d\n", -hang.solve(n));

    return 0;

}