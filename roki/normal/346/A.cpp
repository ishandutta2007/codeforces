#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define xrange(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int n;
int a[100];

bool read() {
    cin >> n;
    forn (i, n)
        cin >> a[i];
    return true;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int G = a[0];
    int B = 0;
    forn (i, n)
        G = gcd(a[i], G), B = max(B, a[i]);
    cout << ((B / G - n) % 2 == 1 ? "Alice" : "Bob") << endl;

}

int main() {

  
    read();
    solve();
    return 0;
}