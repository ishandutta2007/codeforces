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

string a, b;

bool read()
{
    if(!(cin >> a >> b))
        return false;
    return true;
}

void solve()
{
    int cntA = 0, cntB = 0;
    forn (i, a.size())
        cntA += a[i] == '1';
    if(cntA & 1)
        cntA++;
    forn (i, b.size())
        cntB += b[i] == '1';
    if(cntA >= cntB)
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}