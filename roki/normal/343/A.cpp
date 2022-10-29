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
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

li A, B;

bool read()
{
    if(!(cin >> A >> B))
        return false;
    return true;
}

li gcd(li a, li b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve()    
{
    li Q = A, W = B;
    li ans = 0;
    while(Q != 0)
    {
        if(W > Q)
        {
            ans += W / Q;
            W %= Q;
            if(W == 0)
            {
                W = Q;
                ans--;
            }
        }
        else
        {
            ans += Q / W;
            Q %= W;
        }
    }
    cout << ans << endl;
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    while(read())
        solve();
    
    return 0;
}