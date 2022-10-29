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
    int n, k;
    cin >> n >> k;
    int ans[6] = {0, 0, 1, 0, 1, 1};
    if(n < 6 || k * 3 > n)
        cout << -1;
    else
    {
        int u = 0, d = 0;
        if(k * 3 == n && n % 2 == 1)
        {
            cout << "1 2 2 1 1 3 2 3 3 ";
            forn (i, 6)
                ans[i] += 3;
            d = 9;
            u = 3;
        }
        while(u < k)
        {
            for (int i = 0; i < 6 && d < n; ++i, ++d)
                printf("%d ", ans[i] % k + 1);
            forn (i, 6)
                ans[i] += 2;
            u += 2;
        }
        forn (i, n - d)
            printf("%d ", 1);
    }
    return 0;
}