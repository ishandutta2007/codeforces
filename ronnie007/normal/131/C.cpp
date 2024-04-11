#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int mm[16];

void mult(int a, int m)
    {
    int i;
    for(i=0; a>1; ++i)
        {
        while(a%p[i] == 0)
            {
            a /= p[i];
            mm[i] += m;
            }
        }
    }

ll calc()
    {
    ll res=1;
    for(int i=0; i<10; ++i)
        {
        for(int j=0; j<mm[i]; ++j)
            {
            res *= p[i];
            }
        }
        return res;
    }

void clear()
    {
    memset(mm, 0, sizeof(mm));
    }

ll binom(ll n, ll k)
    {
    clear();
    int i;
    for(i=k+1; i<=n; ++i)
        {
        mult(i, 1);
        }
    for(i=1; i<=n-k; ++i)
        {
        mult(i, -1);
        }
    return calc();
    }

int main()
    {
    int i, j;
    int n, m, t;
    ll res=0;
    cin>>n>>m>>t;
    for(i=4; i<t; ++i)
        {
        if (t-i > m || i > n) continue;
        ll cur = binom(n, i);
        cur *= binom(m, t-i);
        res += cur;
        }
    cout<<res<<endl;
    return 0;
    }