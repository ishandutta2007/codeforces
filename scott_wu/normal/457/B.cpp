#include <iostream>
#include <iomanip>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N[2];
ll arr[2][MAXN];

int main()
{
    cin >> N[0] >> N[1];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N[i]; j++)
            cin >> arr[i][j];
        sort (arr[i], arr[i] + N[i]);
    }
    
    ll tot = 0;
    for (int i = 0; i < N[0]; i++)
        tot += arr[0][i];
    
    ll res = 0;
    for (int i = 0; i < N[1] - 1; i++)
        res += min (tot, arr[1][i]);
    res += tot;
    
    ll tot2 = 0;
    for (int i = 0; i < N[1]; i++)
        tot2 += arr[1][i];
    
    ll res2 = 0;
    for (int i = 0; i < N[0] - 1; i++)
        res2 += min (tot2, arr[0][i]);
    res2 += tot2;
    
    cout << min (res, res2) << "\n";
    //system ("Pause");
    return 0;
}