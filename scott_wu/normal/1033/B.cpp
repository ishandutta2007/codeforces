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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        ll A, B;
        cin >> A >> B;
        if (A - 1 > B)
        {
            cout << "NO\n";
            continue;
        }

        ll v = A + B;
        bool prime = true;
        for (ll j = 2; j * j <= v; j++)
            if (v % j == 0)
            {
                prime = false;
                break;
            }
        if (prime) cout << "YES\n";
        else cout << "NO\n";
    }   
}