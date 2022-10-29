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

inline bool read()
{
    if(!(cin >> s))
        return false;
    return true;
}

inline void solve()
{
    int cnt1 = 0, cnt2 = 0;
    forn (i, s.size())
        if(s[i] >= 'A' && s[i] <= 'Z')
            cnt2++;
        else
            cnt1++;
    forn (i, s.size())
        if(cnt2 > cnt1)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] += 'A' - 'a';
        }
        else
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a' - 'A';
        }
        cout << s << endl;
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