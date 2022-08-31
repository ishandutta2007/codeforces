#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

ll A;
vector <ll> pfac;
vector <int> pcnt;
ll fac[MAXN];
ll dp[MAXN];
int nfac;
map <ll, int> dloc;
bool prime[MAXN];

bool cprime (ll x)
{
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            return false;
        }
    return true;
}

void factorise()
{
    ll x = A;
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                x /= i;
                cnt++;
            }
            
            pfac.push_back (i);
            pcnt.push_back (cnt);
        }
    
    if (x > 1)
    {
        pfac.push_back (x);
        pcnt.push_back (1);
    }
    
    nfac = 1;
    for (int i = 0; i < pcnt.size(); i++)
    {
        //cout << pfac[i] << " " << pcnt[i] << "\n";
        nfac *= (pcnt[i] + 1);
    }
    
    for (int i = 0; i < nfac; i++)
    {
        ll res = 1;
        
        int tval = i;
        for (int j = 0; j < pcnt.size(); j++)
        {
            int c = tval % (pcnt[j] + 1);
            tval /= pcnt[j] + 1;
            
            for (int k = 0; k < c; k++)
                res *= pfac[j];
        }
        
        fac[i] = res;
        dloc[res] = i;
    }
}

bool cpow (ll x)
{
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            while (x % i == 0)
                x /= i;
            return x == 1;
        }
    return true;
}

vector <ll> cposs;

void run() // run dp on cposs
{
    for (int i = 0; i < nfac; i++)
    {
        for (int j = 0; j < cposs.size(); j++)
        {
            ll cval = cposs[j];
            if (fac[i] % cval == 0)
            {
                int nloc = dloc[fac[i] / cval];
                dp[nloc] += dp[i];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> A;
    factorise();
    
    for (int i = 0; i < nfac; i++)
        dp[i] = 0;
    dp[nfac-1] = 1;
    
    for (int i = 0; i < MAXN; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    
    for (int i = 2; i * i < MAXN; i++)
    {
        if (prime[i])
            for (int j = i * i; j < MAXN; j += i)
                prime[j] = false;
    }
    
    //for (int i = 0; i < nfac; i++)
    //    cout << fac[i] << "\n";
    
    for (int i = 2; i < MAXN; i++)
    {
        if (prime[i])
        {
            ll cval = i;
            
            cposs.clear();
            while (cval < A)
            {
                if (dloc.find(cval + 1) != dloc.end())
                    cposs.push_back (cval + 1);
                cval *= i;
            }
            
            if (cposs.size() > 0)
                run();
        }
    }
    
    for (int i = 0; i < nfac; i++)
    {
        if (fac[i] > MAXN && cprime (fac[i] - 1))
        {
            cposs.clear();
            cposs.push_back (fac[i]);
            run ();
        }
    }
    
    cout << dp[0] << "\n";
    return 0;
}