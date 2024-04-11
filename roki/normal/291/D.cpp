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
#include<ctime>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, k;

bool read()
{
    if(!(cin >> n >> k))
        return false;
    return true;
}

void solve()
{
    vector<int> a(n, 1);
    a[n - 1] = 0;
    forn (i, k)
    {
        vector<int> b(n);
        forn (j, n)
        {
            int l = 0, r = n - 1;
            int need = n - j - a[j] - 1;
            while(r - l > 1)
            {
                int m = (r + l) >> 1;
                if(a[m] > need)
                    l = m;
                else
                    r = m;
            }
            if(a[l] > need)
                l++;
            b[j] = a[j] + a[l];
            printf("%d ", l + 1);
        }
        a = vector<int> (b);
        printf("\n");
    }
}

int main()
{
    while(read())
    solve();
    return 0;
}