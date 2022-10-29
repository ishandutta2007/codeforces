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

int n, m;

bool read()
{
    if (!(cin >> n >> m))
        return false;
    return true;
}

set<int> bad[100000];

void solve()
{
    set<int> on;
    vector<int> d(n + 1, 0);
    for (int i = 2; i <= n; ++i)
    {
        if (d[i] != 0)
            continue;
        for (int j = i; j <= n; j += i)
            d[j] = i;
    }
    forn (i, m)
    {
        char c;
        int a;
        cin >> c >> a;
        if (c == '+')
        {
            if (on.count(a))
                cout << "Already on" << endl;
            else
            {
                int conf = -1;
                int t = a;
                while (t > 1)
                {
                    bad[d[t]].insert(a);
                    if (bad[d[t]].count(a) < bad[d[t]].size())
                    {
                        set<int>::iterator it1 = bad[d[t]].begin(), it2 = bad[d[t]].end();
                        it2--;
                        conf = *it1 != a ? *it1 : *it2;
                    }
                    t /= d[t];
                }
                if (conf != -1)
                {
                    cout << "Conflict with " << conf << endl;
                    t = a;
                    while (t > 1)
                    {
                        bad[d[t]].erase(a);
                        t /= d[t];
                    }
                }
                else
                {
                    on.insert(a);
                    cout << "Success" << endl;
                }
            }
        }
        else
        {
            if (on.count(a) == 0)
                cout << "Already off" << endl;
            else
                cout << "Success" << endl;
            on.erase(a);
            int t = a;
            while (t > 1)
            {
                bad[d[t]].erase(a);
                t /= d[t];
            }
        }
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