#pragma comment(linker, "/STACK:167177216")

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

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

vector<string> names;

vector< pair<vector<string>, int> > obj;
vector< pair<string, string> > rule;

string s;
int k;
int n;
li mod = 1e9 + 7;

inline void read()
{
    cin >> s >> k;
    n = s.size() * k;
}

li bp(li a, li b)
{
    if(b == 0)
        return 1;
    if(b & 1)
        return a * bp(a, b - 1) % mod;
    return bp(a * a % mod, b >> 1);
}

inline void solve()
{
    li ans = 0;
    li q = bp(2, s.size());
    li oq = bp(q - 1, mod - 2);
    forn (i, s.size())
    {
        if(s[i] == '0' || s[i] == '5')
        {
            li ft = bp(2, i);
            ans = (ans + (ft * (bp(q, k) - 1) % mod) * oq) % mod;
        }
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