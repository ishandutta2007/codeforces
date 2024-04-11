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

    ll N; cin >> N;
    ll sfac = N;
    for (ll i = 2; i * i <= N; i++)
        if (N % i == 0)
        {
            sfac = i;
            break;
        }

    cout << 1 + (N - sfac) / 2 << "\n";
}