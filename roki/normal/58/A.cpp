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

string s;

bool read()
{
    if(!(cin >> s))
        return false;
    return true;
}

void solve()
{
    string cur = "hello";
    forn (i, 5)
        cur += cur;
    int j = 0;
    forn (i, s.size())
        if(cur[j] == s[i])
            j++;
    if(j > 4)
        cout << "YES";
    else
        cout << "NO";
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