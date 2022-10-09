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
    int n, ans = 0;
    cin >> n;
    forn(i, n)
    {
        string s1, s2;
        cin >> s1 >> s2;
        s1 += " ";
        s1 += s2;
        if(st.count(s1) == 0)
            ans++;
        st.insert(s1);
    }
    cout << ans;
    return 0;
}