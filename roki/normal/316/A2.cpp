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

string s;
li c[100][100];

bool ok(int a)
{
    vector<int> nt(10, -1);
    vector<int> ns(10, -1);
    int r = s.size() - 1;
    while(a)
    {
        int cur = a % 10;
        if(s[r] >= '0' && s[r] <= '9' && (s[r] - '0') != cur)
            return false;
        if(s[r] >= 'A' && s[r] <= 'Z')
        {
            int sig = s[r] - 'A';
            if(nt[sig] == -1)
            {
                nt[sig] = cur;
                if(ns[cur] != -1)
                    return false;
                ns[cur] = sig;
            }
            else
                if(nt[sig] != cur)
                    return false;
        }
        r--;
        a /= 10;
    }
    return true;
}

inline void read()
{
    cin >> s;
}

map<char, bool> used;

inline void solve()
{
    forn (i, 100)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    li ans = 1;
    int cnt = 10;
    int cnt0 = 0;
    int kol = 0;
    if(s[0] >= 'A' && s[0] <= 'Z')
    {
        ans *= 9;
        used[s[0]] = true;
        cnt--;
    }
    else
        if(s[0] == '?')
            ans *= 9;
    for (int i = 1; i < s.size(); ++i)
    {
        if(s[i] == '?')
        {
            cnt0++;
        }
        if(s[i] >= 'A' && s[i] <= 'Z' && !used[s[i]])
        {
            kol++;
            used[s[i]] = true;
        }
    }
    ans *= c[cnt][kol];
    for (int i = 2; i <= kol; ++i)
        ans *= i;
    cout << ans;
    forn (i, cnt0)
        cout << 0;

    /*int low = 1;
    for (int i = 0; i < s.size() - 1; ++i)
        low *= 10;
    int gans = 0;
    for (int i = low; i < low * 10; ++i)
    {
        if(ok(i))
            gans++;
    }
    cout << gans << endl;*/
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