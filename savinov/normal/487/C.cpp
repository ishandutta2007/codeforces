#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;
bool isprime (int n)
{
    for (int i=2;i*i<=n;i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}
int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}
int main() {
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    /*
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    */
    int n;
    cin >> n;
    int eps=generator(n);
    if (n==1)
    {
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }
    if (n==4)
    {
        cout << "YES" << endl;
        cout << 1 << endl << 3 << endl << 2 <<endl << 4 << endl;
        return 0;
    }
    if (isprime(n))
    {
        cout << "YES" << endl;
        cout << 1 << endl;
        int her=1;
        for (int i=1;i<n-1;i++)
        {
            her*=-1;
            int her2=her+n-1;
            her2 %= n-1;
            cout << powmod(eps,(long long)her2*i % (n - 1),n)<<"\n";
        }
        cout << n << endl;
    } else
    {
        cout << "NO"<<endl;
    }
    return 0;
}