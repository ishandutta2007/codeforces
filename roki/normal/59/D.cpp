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
int t[100000][3];
int k;
int p[300001];
int pos[300001];

inline bool read()
{
    if(!(cin >> n))
        return false;
    forn (i, 3 * n)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }
    forn (i, n)
        forn (j, 3)
            cin >> t[i][j];
    cin >> k;
    return true;
}

inline void solve()
{
    vector<int> ans;
    set<int> ft;
    set<int> mid;
    set<int> lt;
    bool used[300001];
    memset(used, false, sizeof used);
    forn (i, n)
    {
        bool build = false;
        int leader = t[i][0];
        forn (j, 3)
            if(pos[t[i][j]] < pos[leader])
                leader = t[i][j];
        forn (j, 3)
            if(t[i][j] == k)
                build = true;
        if(build)
        {
            forn (j, 3)
                if(t[i][j] != leader)
                {
                    ft.insert(t[i][j]);
                    used[t[i][j]] = true;
                }
            for (int j = 1; j <= 3 * n; ++j)
                if(!used[j] && j != k)
                    lt.insert(j);
            if(leader != k)
            {
                for (int j = 1; j <= 3 * n; ++j)
                    if(j != k)
                        cout << j << ' ';
                return;
            }
            forn (j, 3 * n - 1)
            {
                int step[3] = {1e9, 1e9, 1e9};
                if(ft.size() != 0)
                    step[0] = *ft.begin();
                if(mid.size() != 0)
                    step[1] = *mid.begin();
                if(lt.size() != 0)
                    step[2] = *lt.begin();
                int cur = 0;
                forn (t, 3)
                    if(t < 2 && step[t] < step[cur] || t == 2 && ft.size() == 0 && step[t] < step[cur])
                        cur = t;
                ans.pb(step[cur]);
                if(cur == 0)
                    ft.erase(ft.begin());
                if(cur == 1)
                    mid.erase(mid.begin());
                if(cur == 2)
                    lt.erase(lt.begin());
            }
            forn (j, ans.size())
                cout << ans[j] << ' ';
            return;
        }
        else
        {
            forn (j, 3)
            {
                mid.insert(t[i][j]);
                used[t[i][j]] = true;
            }
        }
    }
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