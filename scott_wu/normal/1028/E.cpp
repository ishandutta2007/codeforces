#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 300000;

int N;
ll arr[MAXN];
ll res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    bool seen = false;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] != arr[0])
            seen = true;
        arr[i+N] = arr[i];
    }

    if (!seen)
    {
        if (arr[0] == 0)
        {
            // all 0
            cout << "YES\n";
            for (int i = 0; i < N; i++)
            {
                if (i) cout << " ";
                cout << "1";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
        return 0;
    }

    ll cm = 0;
    for (int i = 0; i < N; i++)
        cm = max (cm, arr[i]);

    for (int i = N; i < 2 * N; i++)
    {
        if (arr[i] == cm && arr[i-1] != cm)
        {
            res[i%N] = cm;
            ll ctot = cm;
            for (int j = i - 1; j > i - N; j--)
            {
                if (j == i - 1)
                    ctot = 2 * ctot;
                ctot += arr[j];
                res[j%N] = ctot;
            }
            break;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < N; i++)
        cout << res[i] << " ";
    cout << "\n";
}