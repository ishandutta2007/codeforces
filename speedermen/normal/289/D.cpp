#include <iostream>

using namespace std;

#define ll long long

const ll p = (ll)1e9 + 7;

ll n, k;

ll bin_pow (ll a, ll n) 
{
    if(!n)
        return 1;
        
    if(n % 2)
        return (bin_pow(a, n - 1) * a) % p;
    else 
	{
        ll b = bin_pow(a, n / 2);
        return (b * b) % p;
    }
}

int main()
{
	cin >> n >> k;
	cout << (bin_pow(k, k - 1) * bin_pow(n - k, n - k)) % p << endl;
	
	return 0;
}