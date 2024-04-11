#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string.h>
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

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_baack
#define mp make_pair

int n;
string s;
vector<string> p;
vector<int> l;
vector<int> r;

inline void read()
{
    cin >> s;
    cin >> n;
    l.resize(n);
    r.resize(n);
    p.resize(n);
    forn (i, n)
        cin >> p[i] >> l[i] >> r[i];
}

set<string> used;

inline void solve()
{
    int ans = 0;
    forn (i, s.size())
        for (int j = i; j < s.size(); ++j)
        {
            string cur = s.substr(i, j - i + 1);
            if(used.find(cur) != used.end())
                continue;
            used.insert(cur);
            ans++;
            bool ok = true;
            forn (t, n)
            {
                int cnt = 0;
                forn (q, p[t].size() - cur.size() + 1)
                {
                    if(p[t].substr(q, cur.size()) == cur)
                        cnt++;
                }
                if(cnt < l[t] || cnt > r[t])
                {
                    ans--;
                    ok = false;
                    break;
                }
            }
            if(ok)
                int c = 1;
            
        }
    cout << ans << endl;
}

int main()  
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    read();
    solve();
    return 0;
}