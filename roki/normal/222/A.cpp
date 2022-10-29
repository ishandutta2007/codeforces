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

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, k;
int a[100000];

bool read()
{
    if(!(cin >> n >> k))
        return false;
    forn (i, n)
        cin >> a[i];
    return true;
}

void solve()
{
    int r = n - 1;
    while(r >= 0 && a[r] == a[n - 1])
        r--;
    k--;
    if(r < k)
        cout << r + 1 << endl;
    else
        cout << -1 << endl; 
}

int main() {
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}