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

int n, m;
int cntColumn[100][26], cntRow[100][26];

bool read()
{
    if(!(cin >> n >> m))
        return false;
    return true;
}

char c[100][100];

void solve()
{
    forn (i , n)
        forn (j, m)
        {
            cin >> c[i][j];
            cntColumn[j][c[i][j] - 'a']++;
            cntRow[i][c[i][j] - 'a']++;
        }
    forn (i, n)
        forn (j, m)
        {
            if(cntRow[i][c[i][j] - 'a'] == 1 && cntColumn[j][c[i][j] - 'a'] == 1)
                cout << c[i][j];
        }
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