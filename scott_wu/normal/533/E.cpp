#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll CPOW = 1007;

int N;
int a[MAXN], b[MAXN];

ll chash[MAXN], hash2[MAXN];
ll hash3[MAXN], hash4[MAXN];
ll mpow[MAXN], mpow2[MAXN];

vector <pair <ll, ll> > cleft, cright;

ll mmod (ll x, ll y)
{
    return ((x % y) + y) % y;
}

pair <ll, ll> thash (ll* st, ll* st2, int cloc, int val)
{
    ll left = (st[cloc] * mpow[N+1-cloc]) % MOD;
    ll right = mmod (st[N] - st[cloc] * mpow[N-cloc], MOD);
    ll mid = (mpow[N-cloc] * val) % MOD;
    
    ll tleft = (left + right + mid) % MOD;
    
    left = (st2[cloc] * mpow2[N+1-cloc]) % MOD2;
    right = mmod (st2[N] - st2[cloc] * mpow2[N-cloc], MOD2);
    mid = (mpow2[N-cloc] * val) % MOD2;
    
    ll tright = (left + right + mid) % MOD2;
    
    
    //cout << cloc << " " << val << " " << tleft << " " << tright << "\n";
    return make_pair (tleft, tright);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char ch;
        cin >> ch;
        a[i] = (ch - 'a');
    }
    
    for (int i = 0; i < N; i++)
    {
        char ch;
        cin >> ch;
        b[i] = (ch - 'a');
    }
    
    chash[0] = hash2[0] = 0;
    for (int i = 0; i < N; i++)
    {
        chash[i+1] = (CPOW * chash[i] + a[i]) % MOD;
        hash2[i+1] = (CPOW * hash2[i] + a[i]) % MOD2;
    }
    
    hash3[0] = hash4[0] = 0;
    for (int i = 0; i < N; i++)
    {
        hash3[i+1] = (CPOW * hash3[i] + b[i]) % MOD;
        hash4[i+1] = (CPOW * hash4[i] + b[i]) % MOD2;
    }
    
    mpow[0] = mpow2[0] = 1;
    for (int i = 0; i < N + 100; i++)
    {
        mpow[i+1] = (mpow[i] * CPOW) % MOD;
        mpow2[i+1] = (mpow2[i] * CPOW) % MOD2;
    }
    
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            cleft.push_back (thash (chash, hash2, i, j));
            cright.push_back (thash (hash3, hash4, i, j));
        }
    }
    
    sort (cleft.begin(), cleft.end());
    sort (cright.begin(), cright.end());
    
    int res = 0;
    int lloc = 0, rloc = 0;
    while (lloc < cleft.size() && rloc < cright.size())
    {
        if (cleft[lloc] == cright[rloc])
        {
            res++;
            int nval = rloc;
            while (rloc < cright.size() && cright[rloc] == cright[nval])
                rloc++;
            
            nval = lloc;
            while (lloc < cleft.size() && cleft[lloc] == cleft[nval])
                lloc++;
        }
        else if (cleft[lloc] < cright[rloc])
        {
            int nval = lloc;
            while (lloc < cleft.size() && cleft[lloc] == cleft[nval])
                lloc++;
        }
        else
        {
            int nval = rloc;
            while (rloc < cright.size() && cright[rloc] == cright[nval])
                rloc++;
        }
    }
    
    cout << res << "\n";
    
    return 0;
}