#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int A, B;
vector <int> ares, bres;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> A >> B;
    if (A + B == 0)
    {
        cout << "0\n\n0\n\n";
        return 0;
    }

    ll ctot = A + B;
    ll r = 1;
    while (r * (r + 1) / 2 <= ctot)
        r++;
    r--;


    for (int i = r; i >= 1; i--)
    {
        if (i <= A)
        {
            ares.push_back(i);
            A -= i;
        }
        else
            bres.push_back(i);
    }

    cout << ares.size() << "\n";
    for (int i = 0; i < ares.size(); i++)
    {
        if (i) cout << " ";
        cout << ares[i];
    }
    cout << "\n";

    cout << bres.size() << "\n";
    for (int i = 0; i < bres.size(); i++)
    {
        if (i) cout << " ";
        cout << bres[i];
    }
    cout << "\n";
}