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
    ll A, B;
    cin >> A >> B;
    cout << "YES\n";
    for (ll c = A; c < B; c += 2)
        cout << c << " " << c + 1 << "\n";
}