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

int N;
vector <ll> ans;

void vrun (ll x)
{
    ll leap = N / x;
    ll hi = 1 + ((x - 1) * leap);
    ll res = (hi + 1) * ((ll) x) / 2;
    ans.push_back(res);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            vrun (i);
            if (i < N / i)
                vrun (N / i);
        }
    }
    sort (ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}