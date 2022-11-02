#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mod = 1000000007;
    int a0 = 0, a1 = 0;
    for(int i=0;i<n;i++)
        if (i&1)
            a1 = (a1 + a0 + 1) % mod;
        else
            a0 = (a1 + a0 + 1) % mod;
    cout << (a0 + a1) % mod;
    return 0;
}