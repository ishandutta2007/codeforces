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
string s;

inline bool read()
{
    if(!(cin >> n >> s))
        return false;
    return true;
}

int cur = 0;

void build(string& temp, int p, int dir, int i)
{
    if(p + dir == -1 || p + dir == temp.size())
        return;
    if(temp[p] == temp[p + dir])
    {
        if(p % 2 == 0)
            temp[p] == i + '0', temp[p + dir] = 1 - i + '0';
        else
            temp[p] = 1 - i + '0', temp[p + dir] = i + '0';
        cur++;
    }
    build(temp, p + dir, dir, i);
}

inline void solve()
{
    int ans = 1e9;
    forn (i, 2)
    {
        string temp = s;
        cur = 0;
        forn (j, temp.size() - 1)
        {
            if(temp[j] == temp[j + 1])
            {
                cur = 0;
                build(temp, j + 1, -1, i);
                build(temp, j, 1, i);
                temp = s;
                ans = min(ans, cur);
            }
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
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