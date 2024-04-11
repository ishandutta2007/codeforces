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

using namespace std;

typedef long long li;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int main()
{
    
    int n, s, t;
    cin >> n >> s >> t;
    s--, t--;
    vector<int> to(n);
    forn (i, n)
    {
        cin >> to[i];
        to[i]--;
    }
    vector<bool> u(n, false);
    int ans = 0;
    while(!u[s] && s != t)
    {
        u[s] = true;
        s = to[s];
        ans++;
    }
    if(s == t)
        cout << ans;
    else
        cout << -1;
    return 0;
}