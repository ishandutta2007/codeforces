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

const int nmax = 300;
const long long mod = 1e9 + 7;

int n, m;
char buf[nmax*10];
char s[3][nmax*10];
int a[nmax][nmax];
int pos[nmax][nmax];
long long t[nmax];


bool v(int m){
    if (n % 2 != 0)
        return 0;
    forn(i, n)
        if (pos[i][m] == 2)
            return 0;
    return 1;
}

long long calc(int m){
    long long t[nmax][2];
    memset(t, 0, sizeof t);
    t[0][0] = 1;
    forn(i, n){
        if (pos[i][m] != 1 && pos[i][m+1] != 1)
            t[i+1][1] = (t[i][0] + t[i][1] + t[i+1][1]) % mod;
        if (pos[i][m] != 2 && pos[i][m+1] != 2 && pos[i+1][m] != 2 && pos[i+1][m+1] != 2){
            t[i+2][0] = (t[i+2][0] + t[i][0]) %  mod;
            t[i+2][1] = (t[i+2][1] + t[i][1]) %  mod;
        }
    }
    return t[n][1];
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> m;
    gets(buf);
    forn(i, n){
        gets(buf);
        gets(s[0]);
        gets(s[1]);
        gets(s[2]);
        int now = 1;
        forn(j, m){
            int cnt = 0;
            forn(k, 3)
                forn(l, 3)
                    if (s[k][l + now] == 'O')
                        cnt ++;
            a[i][j] = cnt;
            pos[i][j] = 0;
            if (cnt == 3 || cnt == 2){
                if (s[0][now + 2] == 'O')
                    pos[i][j] = 1;
                else
                    pos[i][j] = 2;
            }
            if (cnt == 6){
                if (s[1][now] == 'O')
                    pos[i][j] = 1;
                else
                    pos[i][j] = 2;
            }
            now += 4;
        }
    }
    t[0] = 1;
    forn(i, m){
        if (v(i))
            t[i+1] = (t[i+1] + t[i]) % mod;
        t[i+2] = (t[i+2] + t[i] * calc(i)) % mod;
    }
    cout << t[m] << endl;

    
    return 0;
}