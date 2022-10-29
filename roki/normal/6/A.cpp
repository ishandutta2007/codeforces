#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
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
    int n = 4;
    vector<int> a(n), v;
    forn (i, n)
    {
        cin >> a[i];
        v.pb(i);
    }
    int ans = 0;
    string p[3] = {"IMPOSSIBLE", "SEGMENT", "TRIANGLE"};
    
    do
    {
        int q = a[v[0]], w = a[v[1]], e = a[v[2]];
        if(q + w > e && e + w > q && e + q > w)
            ans = 2;
        if((q + w == e || e + w == q || e + q == w) && ans < 1)
            ans = 1;
    }while(next_permutation(v.begin(), v.end()));
    cout << p[ans] << endl;
    return 0;
}