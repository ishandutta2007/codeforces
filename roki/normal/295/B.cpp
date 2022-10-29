#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int main()
{
     int n;
    vector < vector < int > > f;
    cin >> n;
    f.resize(n);
    forn (i, n)
    {
        f[i].resize(n);
        forn (j, n)
            cin >> f[i][j];
    }

    vector <li> ans, v(n);
    
    forn (i, n)
    {
        cin >> v[i];
        v[i]--;
    }
    
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                f[j][k] = min(f[j][k], f[j][v[i]] + f[v[i]][k]);
        li sum = 0;
        for (int j = i; j < n; ++j)
            for (int k = i; k < n; ++k)
                sum += f[v[j]][v[k]];
        ans.pb(sum);
    }
    forn (i, n)
        cout << ans[n - i - 1] << ' ';
    return 0;
}