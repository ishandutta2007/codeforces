#include <iostream>
#include <string>
#include <cstdio>
#define fr(i, n) for(int i = 0; i < n; i++)

using namespace std;

string s[1100];
int n, m, ans;
int a[1100][1100];
int qx[1000001];
int qy[1000001];
int len;

void go(int exx, int eyy){
    int ex, ey;
    qx[0] = exx;
    qy[0] = eyy;
    int len = 0;
    int st = 0;
    a[eyy][exx] = 0;

    while(len >= st){
        ex = qx[st];
        ey = qy[st];
        if (ex + 1 < m && a[ey][ex + 1] > a[ey][ex] + 1 && s[ey][ex + 1] != 'T'){
            a[ey][ex + 1] = a[ey][ex] + 1;
            qx[++len] = ex + 1;
            qy[len] = ey;
        }

        if (ex - 1 >= 0 && a[ey][ex - 1] > a[ey][ex] + 1 && s[ey][ex - 1] != 'T'){
            a[ey][ex - 1] = a[ey][ex] + 1;
            qx[++len] = ex - 1;
            qy[len] = ey;
        }

        if (ey + 1 < n && a[ey + 1][ex] > a[ey][ex] + 1 && s[ey + 1][ex] != 'T'){
            a[ey + 1][ex] = a[ey][ex] + 1;
            qx[++len] = ex;
            qy[len] = ey + 1;
        }

        if (ey > 0 && a[ey - 1][ex] > a[ey][ex] + 1 && s[ey - 1][ex] != 'T'){
            a[ey - 1][ex] = a[ey][ex] + 1;
            qx[++len] = ex;
            qy[len] = ey - 1;
        }
        st++;
    }
}

int sx, sy, ex, ey;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    fr(i, n)
        cin >> s[i];

    fr(i, n)
        fr(j, m){
            if (s[i][j] == 'S'){sx = j; sy = i;}
            if (s[i][j] == 'E'){ex = j; ey = i;}
            a[i][j] = 100000000;
        }


    go(ex, ey);
    int tme = a[sy][sx];
    int kol;
    int ans = 0;

    fr(i, n)
        fr(j, m)
            if (s[i][j] >= '1' && s[i][j] <= '9'){
                kol = s[i][j] - '0';
                if (a[i][j] <= tme)
                    ans += kol;
            }

    cout << ans;

    return 0;
}