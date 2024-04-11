#define _USE_MATH_DEFINES

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()

typedef long long li;
typedef double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

string a, b;

bool read() 
{
    return cin >> a >> b;
}

int cnt[2];

void solve() 
{
    forn (i, a.size())
        if (a[i] != b[i])
            cnt[a[i] == '4']++;
    cout << cnt[0] + cnt[1] - min(cnt[0], cnt[1]) << endl;
}

int main() 
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    srand(time(NULL));

    read();   
    solve();

    return 0;
}