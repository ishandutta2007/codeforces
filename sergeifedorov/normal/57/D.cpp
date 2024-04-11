#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

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
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

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

const int nmax = 1010;

char a[nmax][nmax];
int ver[nmax], hor[nmax];
int str[nmax], sto[nmax];
int n, m;

int px[] = {1, 0, -1, 0};
int py[] = {0, 1, 0, -1};

bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int d[nmax][nmax];

void stup(){
    long long res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != 'X'){
                forn(x, n)
                    forn(y, m)
                        d[x][y] = inf;
                d[i][j] = 0;
                while(1){
                    bool upd = 0;
                    forn(x, n)
                        forn(y, m)
                            if (a[x][y] != 'X'){
                                forn(p, 4)
                                    if (check(x + px[p], y + py[p]) && d[x][y] > d[x+px[p]][y + py[p]] + 1){
                                        d[x][y] = d[x+px[p]][y + py[p]] + 1;
                                        upd = 1;
                                    }
                            }
                    if (!upd) break;
                }
                /*forn(x, n){
                    forn(y, m)
                        cout << d[x][y] << " ";
                    cout << endl;
                }
                cout << endl;*/
                forn(x, n)
                    forn(y,m)
                    if (a[x][y] != 'X')
                        res += d[x][y];
            }
    cout << res << endl;
}





int main ()
{

    cin >> n >> m;
    forn(i, n)
        forn(j, m)
            scanf(" %c ", &a[i][j]);
    long long res = 0, cnt = 0;
    memset(str, 255, sizeof str);
    memset(sto, 255, sizeof sto);
    forn(i, n)
        forn(j, m)
            if (a[i][j] != 'X'){
                hor[i] ++;
                ver[j] ++;
                cnt ++;
            }else{
                str[i] = j;
                sto[j] = i;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res += 1ll * hor[i] * hor[j] * abs(j - i);
    
//  cerr << res << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            res += 1ll * ver[i] * ver[j] * abs(j - i);
//  cerr << res << endl;
    for (int i = 0; i < n; i++)
        if (str[i] != -1){
            int lft = str[i], rgt = m - 1 - str[i];
            res += 4ll * lft * rgt;
            int now = str[i];
            for (int j = i + 1; j < n; j++){
                if (str[j] == -1 || str[j] < now) break;
                now = str[j];
                res += 4ll * lft * (m - 1 - now);
            }
            now = str[i];
            for (int j = i + 1; j < n; j++){
                if (str[j] == -1 || str[j] > now) break;
                now = str[j];
                res += 4ll * now * rgt;
            }
        }

    for (int i = 0; i < m; i++)
        if (sto[i] != -1){
            int lft = sto[i], rgt = n - 1 - sto[i];
            res += 4ll * lft * rgt;
            int now = sto[i];
            for (int j = i + 1; j < m; j++){
                if (sto[j] == -1 || sto[j] < now) break;
                now = sto[j];
                res += 4ll * lft * (n - 1 - now);
            }
            now = sto[i];
            for (int j = i + 1; j < m; j++){
                if (sto[j] == -1 || sto[j] > now) break;
                now = sto[j];
                res += 4ll * now * rgt;
            }
        }

//  cout << res << endl;

//  stup();

    printf("%0.9lf\n", 1.0 * res / (1.0 * cnt * cnt));

    return 0;
}