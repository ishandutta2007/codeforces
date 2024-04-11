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
#include<unordered_set>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

char c[1000011];

bool read()
{
    gets(c);
    return true;
}

void solve()
{
    li ans = 0;
    int h = 0;
    int n = strlen(c);
    forn (i, n - 5 + 1)
    {
        string t = "";
        forn (j, 5)
            t += c[i + j];
        if (t == "heavy")
            h++;
        if (t == "metal")
            ans += h;
    }
    cout << ans << endl;
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    read();
    solve();
    return 0;
}