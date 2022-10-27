#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef __int64 ll;
int main()
{
    ll n;
    cin >> n;
    if(n <= 2) cout<<-1;
    else if(n%2 == 0)
    {
        n /= 2;
        cout << (n * n - 1) << " " << (n * n + 1) << endl;
    }
    else if(n%2 == 1)
    {
        n /= 2;
        cout << (2 * n * n + 2 * n) << " " << (2 * n * n + 2 * n + 1) << endl;
    }

    return 0;
}