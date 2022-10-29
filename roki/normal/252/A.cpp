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

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair

typedef long long li;

int main()
{   
    int n;
    cin >> n;
    vector<int> a(n);
    forn (i, n)
        cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            int res = 0;
            for(int k = j; k <= i; ++k)
            {
                res ^= a[k];
            }
            ans = max(ans,res);
        }
    }
    cout << ans << endl;
    return 0;
}