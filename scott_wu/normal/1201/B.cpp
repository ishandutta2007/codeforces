#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);

    int N;
    ll ctot = 0, chi = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll x; cin >> x;
        ctot += x;
        chi = max (chi, x);
    }

    if (ctot % 2 == 0 && chi * 2 <= ctot)
        cout << "YES\n";
    else
        cout << "NO\n";
}