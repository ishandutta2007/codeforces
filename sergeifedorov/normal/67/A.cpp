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

const int nmax = 1010;

char a[nmax];
int n, res;
int b[nmax];


int main ()
{

    cin >> n;
    forn(i, n-1)
        cin >> a[i + 1];
    int res= 0 ;
    forn(i, n)
        b[i] = 1;
    while(1){
        int now = res;
        for (int i = 0; i < n; i++){
                while (a[i+1] == 'R' && b[i+1] <= b[i]){
                    res ++;
                    b[i+1] ++;
                }
                while (a[i+1] == 'L' && b[i+1] >= b[i]){
                    res ++;
                    b[i] ++;
                }
                if (a[i+1] == '=' && b[i+1] != b[i]){
                    res += abs(b[i+1] - b[i]);
                    b[i+1] = max(b[i+1], b[i]);
                    b[i] = max(b[i], b[i+1]);
                }
            }
        if (now == res) break;
    }
    forn(i, n)
        cout << b[i] << " ";
    cout << endl;



    return 0;
}