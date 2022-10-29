#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;

#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ft first
#define sc second

int n;
const int N = 1010;
int a[N];

bool read() {
    cin >> n;
    forn (i, n)
        cin >> a[i];
    return true;
}

void solve() {
    int ans = 0;
    int l = 0;
    while(l < n)
    {
        if (a[l] == 1)
        {
            ans++;
            while(l < n && a[l] == 1)
                ans++, l++;
        }
        else
            l++;
    }
    if (ans)
        ans--;

    cout << ans << endl;
}


int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif

    read();
    solve();

    return 0;
}