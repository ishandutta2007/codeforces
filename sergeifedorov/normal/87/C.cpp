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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

const int nmax = 100100;


int n;
int xo[nmax];
int t[nmax];
bool us[nmax];
pii pos[nmax];
int res[nmax];

int main ()
{
    t[0] = 0;
    for (int i = 1; i < nmax; i++){
        t[i] = 0;
        int h = 0;
        for (int k = 2; k * (k+1) <= 2 * i; k++){
            int x = (i - (k + 1) * k / 2);
            if (x % k != 0) continue;
            x /= k;
            int now = xo[x+k] ^ xo[x];
//          cerr << i <<  "-" << k << " "<< now << endl;
            us[now] = 1;
            pos[h++] = mp(now, k);
        }
        while (us[t[i]]) t[i] ++;
        res[i] = -1;
        forn(j, h){
            us[pos[j].fs] = 0;
            if (pos[j].fs == 0 && (res[i] == -1 || res[i] > pos[j].sc))
                res[i] = pos[j].sc;
        }
        xo[i] = xo[i-1] ^ t[i]; 
//      cerr << i << " " << t[i] <<" " << res[i] << endl;
    }
    int n;
    cin >> n;
    cout << res[n] << endl;
    return 0;
    if (t[n] == 0)
        puts("-1");
    else
        cout << res[n] << endl;





        return 0;
}