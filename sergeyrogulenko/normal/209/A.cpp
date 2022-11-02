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

const int64 P = 1000000007;

int n;
int64 s0, s1;

int main ()
{
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);    
    cin >> n;
    s0 = s1 = 0;
    for (int i = 1; i <= n; i ++) {
        swap (s0, s1);
        s0 = (s0 + s1 + 1) % P;    
    }    
    cout << (s0 + s1) % P << endl;

    return 0;
}