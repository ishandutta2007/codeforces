#include <bits/stdc++.h>
using namespace std;

const int MAXP = 200000;
vector<long long> primes;
int sv[MAXP];

void sieve()
{
    for(long long p = 2; p < MAXP; p++)
    {
        if(!sv[p])
        {
            primes.push_back(p);
            for(long long q = 2*p; q < MAXP; q += p)
            {
                sv[q] = p;
            }
        }
    }
}

int main()
{
    sieve();
    long long n;
    cin >> n;
    if(n % 2 == 0)
    {
        cout << n / 2 << endl;
        return 0;
    }
    for(auto p : primes)
    {
        if(n % p == 0)
        {
            cout << 1 + (n - p)/2 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}