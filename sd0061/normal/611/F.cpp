#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 500005;
const int Q = 1e9 + 7;

int n , m , K , d[N];
char str[N];
int sx[(1 << 20) + 5] , sy[(1 << 20) + 5];
int dx[] = {1 , 0 , -1 , 0};
int dy[] = {0 , -1 , 0 , 1};

int fxm[21][N];
int fxn[21][N];
int fym[21][N];
int fyn[21][N];

int main() {
    scanf("%d%d%d" , &K , &n , &m);
    scanf("%s" , str);
    int SX = 0 , SY = 0;
    int mxx , mxy , mnx , mny;
    mxx = mxy = mnx = mny = 0;
    for (int i = 0 ; i < K ; ++ i) {
        if (str[i] == 'U') d[i] = 2;
        if (str[i] == 'D') d[i] = 0;
        if (str[i] == 'L') d[i] = 1;
        if (str[i] == 'R') d[i] = 3;
        SX += dx[d[i]];
        SY += dy[d[i]];
        mxx = max(mxx , SX);
        mxy = max(mxy , SY);
        mnx = min(mnx , SX);
        mny = min(mny , SY);
    }
    int RX = mxx - mnx + 1 , RY = mxy - mny + 1;
    if (SX == 0 && SY == 0 && n >= RX && m >= RY) {
        puts("-1");
        return 0;
    }
    int L = max(n , max(m , K)) + 10;
    for (int i = 0 ; i < 1 << 20 ; ++ i) {
        int D = d[i % K];
        sx[i + 1] = sx[i] + dx[D];
        sy[i + 1] = sy[i] + dy[D];
        fxm[0][i] = max(dx[D] , 0);
        fxn[0][i] = min(dx[D] , 0);
        fym[0][i] = max(dy[D] , 0);
        fyn[0][i] = min(dy[D] , 0);
    }
    int Lev = 0;
    for (int k = 1 ; 1 << k <= L + L; ++ k) {
        for (int i = 0 ; i < K ; ++ i) {
            int x = i + (1 << k - 1) , y = x % K;
            fxm[k][i] = max(fxm[k - 1][i] , fxm[k - 1][y] + sx[x] - sx[i]);
            fxn[k][i] = min(fxn[k - 1][i] , fxn[k - 1][y] + sx[x] - sx[i]);
            fym[k][i] = max(fym[k - 1][i] , fym[k - 1][y] + sy[x] - sy[i]);
            fyn[k][i] = min(fyn[k - 1][i] , fyn[k - 1][y] + sy[x] - sy[i]);
        }
        Lev = k;
    }
    int res = 0;

    SX = SY = 0;
    int s = 0;
    int NN = n , MM = m;
    for (int k = 0 ;  ; ) {

        if (n == 0 || m == 0)
            break;
        static int ss[4];
        //memset(ss , -1 , sizeof(ss));
        int step = 10000000;
        if (1) {
            int l = k , y = 0;
            for (int i = Lev ; i >= 0 ; -- i) {
                if (fxn[i][l % K] >= -SX - y) {
                    y += fxn[i][l % K];
                    l += 1 << i;
                }
            }
            ss[0] = step;
            step = min(step , l - k);
        }
        if (1) {
            int l = k , y = 0;
            for (int i = Lev ; i >= 0 ; -- i) {
                if (fyn[i][l % K] >= -SY - y) {
                    y += fyn[i][l % K];
                    l += 1 << i;
                }
            }
            ss[1] = step;
            step = min(step , l - k);
        }
        if (1) {
            int l = k , y = 0;
            for (int i = Lev ; i >= 0 ; -- i) {
                if (fxm[i][l % K] <= NN - n - SX - y) {
                    y += fxm[i][l % K];
                    l += 1 << i;
                }
            }
            ss[2] = step;
            step = min(step , l - k);
        }
        if (1) {
            int l = k , y = 0;
            for (int i = Lev ; i >= 0 ; -- i) {
                if (fym[i][l % K] <= MM - m - SY - y) {
                    y += fym[i][l % K];
                    l += 1 << i;
                }
            }
            ss[3] = step;
            step = min(step , l - k);
        }
        ++ step;
        s += step , s %= Q;
        SX += sx[k + step] - sx[k];
        SY += sy[k + step] - sy[k];


        if (SX < 0) {
            -- n;
            ++ SX;
            res += (LL)m * s % Q;
            res %= Q;
        } else if (SY < 0) {
            -- m;
            ++ SY;
            res += (LL)n * s % Q;
            res %= Q;
        } else if (SX > NN - n) {
            -- n;
            res += (LL)m * s % Q;
            res %= Q;
        } else if (SY > MM - m) {
            -- m;
            res += (LL)n * s % Q;
            res %= Q;
        }
        k += step;
        k %= K;

    }
    cout << res << endl;
    return 0;
}
/*
  2  2  2  2  2  1
  5  5  5  5  5  1
  8  8  8  8  8  1
 11 11 11 11 11  1
134
 */