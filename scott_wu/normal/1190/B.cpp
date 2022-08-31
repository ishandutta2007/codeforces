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
const int MAXN = 100100;
const string WIN = "sjfnb";
const string LOSE = "cslnb";

int N;
ll arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort (arr, arr + N);

    bool bad = false;
    int nx = 0;
    for (int i = 0; i + 1 < N; i++)
    {
        if (arr[i] == arr[i+1])
        {
            nx++;
            if (i > 0 && (arr[i] == arr[i-1] + 1))
                bad = true;
            if (arr[i] == 0)
                bad = true;
        }
    }
    if (nx >= 2 || bad)
    {
        cout << LOSE << "\n";
        return 0;
    }

    ll vtot = 0;
    for (int i = 0; i < N; i++)
        vtot += (arr[i] - i);
    if (vtot % 2 == 0)
    {
        cout << LOSE << "\n";
    }
    else
    {
        cout << WIN << "\n";
    }
}