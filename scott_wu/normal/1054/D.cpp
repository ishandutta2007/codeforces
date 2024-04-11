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
const int MAXN = 200100;

int N, K;
int arr[MAXN];
map <int, int> mm;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int cm = 0;
    mm[0]++;
    for (int i = 0; i < N; i++)
    {
        cm = cm ^ arr[i];
        if (cm >= (1 << (K - 1)))
        {
            cm ^= (1 << K) - 1;
        }
        //cout << cm << "\n";
        mm[cm]++;
    }

    ll ntot = N * (ll) (N + 1) / 2;
    for (pair <int, int> p : mm)
    {
        ll v = p.second;
        ll l = v / 2;
        ll r = v - l;
        ntot -= (l * (l - 1)) / 2 + (r * (r - 1)) / 2;
    }
    cout << ntot << "\n";
}