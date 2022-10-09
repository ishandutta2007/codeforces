#include <iostream>
#include <cstdio>

#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())

using namespace std;

set<string> st;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    vector<int> v;
    int n, m;
    cin >> n >> m;
    v.resize(n);
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        for(int i = a; i <= b; i++)
            v[i]++;
    }
    forv(i, v)
    {
        if(v[i] != 1)
        {
            cout << i + 1 << ' ' << v[i];
            return 0;
        }
    }
    cout << "OK";
    return 0;
}