#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int N, M;
set <ll> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    ll ct = 0;
    for (int i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        ct += x;
        s.insert(ct);
    }
    cin >> M;
    int ans = 0;
    ll cm = 0;
    for (int i = 0; i < M; i++)
    {
        ll x;
        cin >> x;
        cm += x;
        if (s.find(cm) != s.end())
            ans++;
    }
    if (cm != ct)
    {
        cout << "-1\n";
        return 0;
    }
    cout << ans << "\n";
}