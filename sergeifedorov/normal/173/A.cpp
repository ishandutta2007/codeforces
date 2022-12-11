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

const int nmax = 1010;

int n, m, k;
int st[nmax][nmax];
string a, b;

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b % a, a);
}

bool win(char a, char b){
    if (a == 'R') return b == 'P';
    if (a == 'S') return b == 'R';
    if (a == 'P') return b == 'S';
    return 0;
}

int main ()
{
    int n;
    cin >> n >> a >> b;
    m = a.size();
    k = b.size();

    int w = gcd(m, k);
    int cir = m * k / w;
    memset(st, 255, sizeof st);

    for (int i = 0; i < cir; i ++){
        st[i % m][i % k] = i;
    }

    int r1, r2;
    r1 = r2 = 0;

    forn(i, m)
        forn(j, k)
            if (st[i][j] != -1){
                if (a[i] == b[j]) continue;
                if (st[i][j] >= n) continue;
                int now = (n + cir - 1 - st[i][j]) / cir;
                if (win(a[i], b[j]))
                    r1 += now;
                else
                    r2 += now;
            }
    cout << r1 << " "  << r2 << endl;
    

    return 0;
}