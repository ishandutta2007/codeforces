#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <ctime>
#include <cassert>
#include <complex>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i ++)
#define ford(i,n) for (int j = (int)(n)-1; j >= 0; j --)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define fs first
#define sc second
#define I (int)
#define seta(x,y) memset (x, y, sizeof (x))

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const int inf = (1 << 30) - 1;
const int64 inf64 = (1LL << 62) - 1;
const ldb eps = 1e-9;
const ldb pi = acosl(-1.); 

int t[100][100][100];

int go (int i, int j, int k) {
    if (t[i][j][k] != -1)
        return t[i][j][k];
    if (i + j == 0 || i + k == 0 || j + k == 0)
        return t[i][j][k] = 0;
    t[i][j][k] = i + j + k - 1;
    if (i > 0 && j > 0)
        t[i][j][k] = min (t[i][j][k], 1 + go (i-1, j-1, k+1));
    if (i > 0 && k > 0)
        t[i][j][k] = min (t[i][j][k], 1 + go (i-1, j+1, k-1));
    if (j > 0 && k > 0)
        t[i][j][k] = min (t[i][j][k], 1 + go (i+1, j-1, k-1));
    return t[i][j][k];
}

int64 calc2 (int64 i, int64 j, int64 k) {
    int64 res = i + j + k - 1;
    int64 x = min (j, k);
    j -= x;
    k -= x;
    if (j % 2 == 0 && k % 2 == 0)
        res = min (res, x + j + k);
    return res;
}

int64 calc (int64 i, int64 j, int64 k) {
    if (i == 0 && j == 0 && k == 0)
        return 0;
    return min (calc2 (i, j, k), min (calc2 (j, k, i), calc2 (k, i, j)));
}

int main ()
{
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);    
//    seta (t, 255);
//    t[0][0][0] = 0;
    int64 x, y, z;
    cin >> x >> y >> z;
    cout << calc (x, y, z) << endl;
    return 0;
    forn (i, 100)
        forn (j, 100)
            forn (k, 100)
                go (i, j, k);    
    for (int i= 0; i < 50; i ++)
        for (int j = 0; j < 50; j ++)
            for (int k = 0; k < 50; k ++) {
                if (t[i][j][k] != calc (i, j, k))
                    cerr << i << " " << j << " " << k << " " << t[i][j][k] << " " << calc(i, j, k) << endl;
                assert (t[i][j][k] == calc (i, j, k));
            }
    
    return 0;
}