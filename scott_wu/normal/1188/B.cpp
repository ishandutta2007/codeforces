#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;

map <int, int> mm;

int main()
{
    ios_base::sync_with_stdio(0);

    int N, P, K;
    cin >> N >> P >> K;
    for (int i = 0; i < N; i++)
    {
        ll x; cin >> x;
        ll y = (x * x) % P;
        y = (y * y) % P;
        y = ((y - K * x) % P + P) % P;
        mm[y] += 1;
    }

    ll res = 0;
    for (auto it : mm)
    {
        ll x = it.second;
        res += (x * (x - 1)) / 2;
    }
    cout << res << "\n";
}