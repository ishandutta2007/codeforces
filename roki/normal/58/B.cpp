#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<unordered_set>
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

int n;

bool read()
{
    if(!(cin >> n))
        return false;
    return true;
}

void solve()
{
    while(n > 1)
    {
        cout << n << ' ';
        for (int i = 2; i <= n; ++i)
            if(n % i == 0)
            {
                n /= i;
                break;
            }
    }
    cout << 1 << endl;
}

int main() {
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    read();
        solve();
    return 0;
}