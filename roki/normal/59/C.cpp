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

inline void solve()
{
    vector<bool> used(n, false);
    int l = 0, r = s.size() - 1;
    bool ok = true;
    while(l <= r)
    {
        if(s[l] == '?' && (s[r] >= 'a' && s[r] <= 'z'))
            s[l] = s[r], used[s[r] - 'a'] = true;
        if(s[r] == '?' && (s[l] >= 'a' && s[l] <= 'z'))
            s[r] = s[l], used[s[l] - 'a'] = true;
        if(s[l] != s[r] && s[l] >= 'a' && s[l] <= 'z' && s[r] >= 'a' && s[r] <= 'z')
            ok = false;
        if(s[l] == s[r] && s[l] >= 'a' && s[l] <= 'z')
            used[s[l] - 'a'] = true;
        l++, r--;
    }
    l = s.size() / 2 - ((s.size() + 1) & 1), r = s.size() / 2;
    while(l >= 0 && r < s.size())
    {
        int ft = 0;
        if(s[l] == '?')
        {
            forn (i, n)
                if(!used[i])
                    ft = i;
            s[l] = s[r] = 'a' + ft;
            used[ft] = true;
        }
        l--, r++;
    }
    forn (i, n)
        if(used[i] == false)
            ok = false;
    if(!ok)
        s = "IMPOSSIBLE"; 
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