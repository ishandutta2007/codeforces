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
    int m, n, t = 1e9, a[100000];
    cin >> m;
    forn (i, m)
    {
        int b;
        cin >> b;
        t = min(t, b);
    }
    cin >> n;
    forn (i, n)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0, k = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        ans += a[i];
        k++;
        if(k == t)
        {
            i -= 2;
            k = 0;
        }
    }
    cout << ans << endl;
    return 0;
}