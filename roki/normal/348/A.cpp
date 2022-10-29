#pragma comment(linker, "/STACK:167177216")
 
#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
#include<ctime>
 
using namespace std;
typedef long double ld;
 
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
 
int n;
long long a[100010];
inline bool read() {
    if(!(cin >> n))
        return false;
    forn (i, n)
        cin >> a[i];
    return true;
}
 
inline void solve() {
    long long sum = 0;
    long long maxval = 0;
    forn (i, n)
        sum += a[i], maxval = max(maxval, a[i]);
    cout << max((sum + n - 2) / (n - 1), maxval) << endl;
}
 
int main() {
    while(read())
        solve();
 
    return 0;
}