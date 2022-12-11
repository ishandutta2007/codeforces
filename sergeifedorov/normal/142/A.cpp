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

long long rmin = 1e18;
long long rmax = -1e18;
    
void update(long long a, long long b, long long c){
    rmin = min(rmin, (a + 1) * (b + 2) * (c + 2) - a * b * c);
    rmax = max(rmax, (a + 1) * (b + 2) * (c + 2) - a * b * c);
}

void update(long long a, long long n){
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            update(a, i, n/i);  
}

int main ()
{
    long long n;
    cin >> n;
//  long long m = n;
    for (long long i = 1; i * i <= n; i++)
        if (n % i == 0){
            update(i, n / i);
            update(n/i, i);         
        }
    cout << rmin << " " << rmax << endl;



    return 0;
}