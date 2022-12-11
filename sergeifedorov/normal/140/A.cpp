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
const int inf = (int)1e9 + 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}



void no(){
    puts("NO");
    exit(0);
}

void yes(){
    puts("YES");
    exit(0);
}


int main ()
{
    long double n, r1, r2;
    cin >> n >> r2 >> r1;

    if (r2 < r1)
        no();
    if (r2 < 2 * r1){
        if (n <= 1)
            yes();
        no();
    }


    long double alph = asinl(r1 / (r2 - r1));
//  cerr << alph << endl;
    if (alph * n > pi + 1e-9)
        puts("NO");
    else
        puts("YES");



    return 0;
}