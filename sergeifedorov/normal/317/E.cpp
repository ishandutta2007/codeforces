#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 410;
const int qmax = 1e6 + 1e5;

int px[] = {-1, 0, 1, 0};
int py[] = {0, -1, 0, 1};
char ch[] = {'L', 'D', 'R', 'U'};

int vx, vy, sx, sy;

int a[nmax][nmax];
int used[nmax][nmax];
char res[qmax];
int m, M;
int x[nmax], y[nmax];

void no() {
    puts("-1");
    exit(0);
}

void move(int &x, int &y, int id) {
    int nx = x + px[id];
    int ny = y + py[id];
    if (nx >= 0 && ny >= 0 && nx < nmax && ny < nmax && a[nx][ny] == 1) return;
    x = nx;
    y = ny;
}

void move(int id) {
    move(vx, vy, id);
    move(sx, sy, id);
    res[m ++] = ch[id];
}

bool move(int x, int y, int wx, int wy) {
    if (mp(x, y) == mp(wx, wy)) return 1;
    used[x][y] = 1;
    forn(i, 4) {
        int nx = x + px[i];
        int ny = y + py[i];
        if (nx >= 0 && ny >= 0 && nx < nmax && ny < nmax && a[nx][ny] == 0 && !used[nx][ny]) {
            pii o1, o2;
            o1 = mp(vx, vy);
            o2 = mp(sx, sy);
            move(i);
            if (move(nx, ny, wx, wy)) return 1;
            vx = o1.fs; vy = o1.sc;
            sx = o2.fs; sy = o2.sc;

            res[m] = 0;
            m --;
        }
    }
    return 0;
}

void dfs(int x, int y) {
    used[x][y] = 1;
    forn(i, 4) {
        int nx = x + px[i];
        int ny = y + py[i];
        if (nx >= 0 && ny >= 0 && nx < nmax && ny < nmax && a[nx][ny] == 0 && !used[nx][ny])
            dfs(nx, ny);
    }
}

void Gmove(int x, int y, int sx, int sy) {
    while(1) {
    bool upd = 0;
    forn(i, 4) {
        int nx = x + px[i];
        int ny = y + py[i];
        if (abs(x - sx) >= abs(nx - sx) && abs(y - sy) >= abs(ny - sy)) {
            move(i);
            upd= 1;
            x = nx;
            y = ny;
        }
    }
    if (!upd) break;
    }   
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> vx >> vy >> sx >> sy;
    vx += 150;
    vy += 150;
    sx += 150;
    sy += 150;
    m = 0;
    cin >> M;
    forn(i, M) {
        cin >> x[i] >> y[i];
        x[i] += 150;
        y[i] += 150;
        a[x[i]][y[i]] = 1;
    }
    if (mp(vx, vy) == mp(sx, sy)) {
        puts("L");
        exit(0);    
    }
    if (M == 0) no();

    dfs(vx, vy);
    if (!used[sx][sy]) no();
    m = 0;
    pii pos = mp(nmax, nmax);
    forn(i, nmax)
        forn(j,nmax)
            if (used[i][j])
                pos = min(pos, mp(i, j));
    if (pos != mp(0, 0)) {
        while(mp(vx, vy) != mp(sx, sy)) {
            memset(used, 0, sizeof used);
            move(vx, vy, sx, sy);
        }
        cout << res << endl;
        exit(0);
    }

    memset(used, 0, sizeof used);
    move(vx, vy, 0, 0);
    forn(i, 500)
        move(0);
    forn(i, 500)
        move(1);
    
    if (sx >= 0 && sy >= 0) {
        memset(used, 0, sizeof used);
        move(sx, sy, 0, 0);
    }
    if (sy > 0)
        forn(i, 500)
            move(1);
    if (sx > 0)
        forn(i, 500)
            move(1);

    assert(sx <= 0 && sy <= 0 && vx <= 0 && vy <= 0);       
    
    if (vx < sx) {
        pii now = mp(nmax, nmax);
        forn(i, M)
            if (x[i] < now.fs)
                now = mp(x[i], y[i]);
        Gmove(sx, sy, now.fs - 1, now.sc);
        while (vx != sx)
            move(2);
    }
    if (vx > sx) {
        pii now = mp(-nmax, nmax);
        forn(i, M)
            if (x[i] > now.fs)
                now = mp(x[i], y[i]);
        while (sx < nmax || vx < nmax)
            move(2);
        Gmove(sx, sy, now.fs + 1, now.sc);
        while (vx != sx)
            move(0);
    }
    forn(i, 500) {
        move(1);
    }
    forn(i, 500) {
        move(0);
    }

    if (vy < sy) {
        pii now = mp(nmax, nmax);
        forn(i, M)
            if (y[i] < now.sc)
                now = mp(x[i], y[i]);
        Gmove(sx, sy, now.fs, now.sc - 1);
        while (vy != sy)
            move(3);
    }
    if (vy > sy) {
        pii now = mp(-nmax, -nmax);
        forn(i, M)
            if (y[i] > now.sc)
                now = mp(x[i], y[i]);
        while (sy < nmax || vy < nmax)
            move(3);
        Gmove(sx, sy, now.fs, now.sc + 1);
        while (vy != sy)
            move(1);
    }


    cout << res << endl;            

    return 0;
}