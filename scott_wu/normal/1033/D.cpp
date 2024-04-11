#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXP = 1400100;
const int MAXD = 2100;
const ll MOD = 998244353;

int N;
ll num[MAXP];

bool prime[MAXP];
vector <int> plist; // list of primes <= 1e6
//int pcount[MAXP]; // divisibility of this prime

map <ll, int> cmap; // all primes and their divisibilities

int cdig[MAXD]; //digits of power of 2

ll gcd (ll a, ll b)
{
    return ((b == 0) ? a : gcd (b, a % b));
}

ll sq (ll x)
{
    ll rt = sqrt (x) + 0.1;
    if (rt * rt == x)
        return rt;
    return -1;
}

ll mmult (ll a, ll b, ll mod)
{
    ll aleft = a / 1000000000, aright = a % 1000000000;
    ll bleft = b / 1000000000, bright = b % 1000000000;
    
    ull x = (aleft * bleft) % mod, y = (aleft * bright + bleft * aright) % mod, z = (bright * aright) % mod;
    //cout << x << " " << y << " " << z << "\n";
    
    for (int i = 0; i < 18; i++)
        x = (10 * x) % mod;
    for (int i = 0; i < 9; i++)
        y = (10 * y) % mod;
    
    //cout << a << " " << b << " " << mod << " " << (x + y + z) % mod << "\n";
    return (x + y + z) % mod;
    
    //long double x = (a * (long double) b) + 0.5;
    //return (ll) (x - ((ll) x / mod) * (long double) mod);
}

ll mpow (ll b, ll p, ll mod)
{
    ll res = 1, cval = b;
    for (int i = 0; i < 60; i++)
    {
        if (p & (1LL << (ll) i))
            res = mmult (res, cval, mod);
        cval = mmult (cval, cval, mod);
    }
    return res;
}

bool mrtest (ll n) // prime test
{
    //cout << n << "\n";
    
    int s = 0;
    ll d = n - 1;
    while (d % 2 == 0)
    {
        d /= 2;
        s++;
    }
    
    //cout << s << " " << d << "\n";
    
    
    for (int i = 0; i < 10; i++)
    {
        int a = plist[i];
        ll x = mpow (a, d, n);
        
        //cout << x << "\n";
        if (x == 1 || x == n - 1)
            continue;
        
        bool found = false;
        for (int j = 0; j < s - 1; j++)
        {
            x = mmult (x, x, n);
            if (x == 1) return false;
            if (x == n - 1)
            {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
    //return x < 1e12;
}

void sieve()
{
    for (int i = 1; i < MAXP; i++)
        prime[i] = true;
    prime[1] = false;
    
    plist.clear();
    for (int i = 2; i < MAXP; i++)
        if (prime[i])
        {
            plist.push_back (i);
            
            if (i > 2000) continue;
            for (int j = i * i; j < MAXP; j += i)
                prime[j] = false;
        }
}

inline void inc (ll x)
{
    if (cmap.find(x) != cmap.end())
        cmap[x]++;
    else
        cmap[x] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    sieve();
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < plist.size(); j++)
        {
            while (num[i] % plist[j] == 0)
            {
                num[i] /= plist[j];
                inc (plist[j]);
            }
        }
        
        if (num[i] > 1)
        {
            if (sq (num[i]) != -1)
            {
                inc (sq (num[i]));
                inc (sq (num[i]));
                num[i] = 1;
            }
            else if (mrtest (num[i]))
            {
                inc (num[i]);
                num[i] = 1;
            }
        }
    }
    
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (num[i] != num[j] && gcd (num[i], num[j]) > 1)
            {
                ll g = gcd (num[i], num[j]);
                for (int k = 0; k < N; k++)
                    if (num[k] % g == 0)
                    {
                        inc (g);
                        inc (num[k] / g);
                        num[k] = 1;
                    }
            }
    
    for (map <ll, int>::iterator it = cmap.begin(); it != cmap.end(); it++)
    {
        if (it->first > 2000000)
        {
            for (int i = 0; i < N; i++)
                if (num[i] % it->first == 0)
                {
                    inc (it->first);
                    inc (num[i] / it->first);
                    num[i] = 1;
                }
        }
    }

    ll res = 1;
    for (int i = 0; i < N; i++)
        if (num[i] > 1)
        {
            inc (num[i]);
            inc (-num[i]);
        }
    
    for (map <ll, int>::iterator it = cmap.begin(); it != cmap.end(); it++)
    {
        res = res * ((it->second) + 1) % MOD;
    }
    
    cout << res << "\n";
    return 0;
}