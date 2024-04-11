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



#define N 200



int T, n;

int t[N];

bool vis[N<<1][N<<1];



struct fireworks {

    int x, y;

    int d, t, lvl;

    fireworks(int x = 0, int y = 0, int d = 0, int t = 0, int lvl = 0) : x(x), y(y), d(d), t(t), lvl(lvl) {};

    bool operator< (const fireworks &_) const {

        if (x != _.x) return x < _.x;

        if (y != _.y) return y < _.y;

        if (d != _.d) return d < _.d;

        if (t != _.t) return t < _.t;

        return lvl < _.lvl;

    }

} tmp, tp1, tp2;



set<fireworks> q;

set<fireworks> nq;

set<fireworks> :: iterator it;



int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};

int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};



int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i ++) {

        scanf("%d", &t[i]);

    }

    tmp.x = N, tmp.y = N, tmp.d = 0, tmp.t = t[1], tmp.lvl = 1;

    q.insert(tmp);

    while (!q.empty()) {

        nq.clear();

        for (it = q.begin(); it != q.end(); it ++) {

            tmp = *it;

            int x = tmp.x, y = tmp.y;

            for (int i = 0; i < tmp.t; i ++) {

                vis[x][y] = 1;

                if (i != tmp.t - 1) x += dx[tmp.d], y += dy[tmp.d];

            }

            if (tmp.lvl == n) continue;

            for (int r = -1; r <= 1; r += 2) {

                int dd = (tmp.d + r + 8) % 8;

                tp1 = fireworks(x + dx[dd], y + dy[dd], dd, t[tmp.lvl+1], tmp.lvl + 1);

                nq.insert(tp1);

            }

        }

        swap(q, nq);

    }

    int ans = 0;

    for (int i = 0; i < (N<<1); i ++)

    for (int j = 0; j < (N<<1); j ++) if (vis[i][j]) ans ++;

    cout<<ans<<endl;

    return 0;

}