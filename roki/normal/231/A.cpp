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

const li INF = (1LL << 31) - 1;

int main()
{
    
    int n;
    cin >> n;
    int ans = 0;
    forn (i, n)
    {
        int s = 0;
        forn (j, 3)
        {
            int k;
            cin >> k;
            s += k;
        }
        if(s >= 2)
            ans++;
    }
    cout << ans;
    return 0;
}