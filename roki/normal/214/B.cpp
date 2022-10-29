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

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n;
vector<int> a;

int u[10];

inline void read()
{
    cin >> n;
    a.resize(n);
    forn (i, n)
    {
        cin >> a[i];
        u[a[i]]++;
    }
}

inline void solve()
{
    if(u[0] == 0)
    {
        cout << -1;
        return;
    }
    int sum = 0;
    forn (i, 10)
        sum += u[i] * i;
    if(sum % 3 != 0)
    {
        int t = sum % 3;
        while(t < 10 && u[t] == 0)
            t += 3;
        if(t > 9)
        {
            pair<int, int> best = mp(1e9, 1e9);
            for (int i = 1; i < 10; ++i)
                for (int j = 1; j <= i; ++j)
                    if((u[i] > 0 && u[j] > 0 && i != j || i == j && u[i] > 1) && (i + j) % 3 == sum % 3)
                    {
                        if(mp(i, j) < best)
                            best = mp(i, j);
                    }
            u[best.first]--;
            u[best.second]--;
        }
        else
            u[t]--;
    }
    int cnt = 0;
    for (int i = 1; i < 10; ++i)
        cnt += i * u[i];
    if(cnt == 0)
    {
        cout << 0;
        return;
    }
    for (int i = 9; i >= 0; --i)
        forn (j, u[i])
            cout << i;
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