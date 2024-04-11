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

int N, K;
int nc[110];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        nc[x]++;
    }

    int mm = 0;
    for (int i = 0; i < 110; i++) mm = max (mm, nc[i]);
    while (mm % K != 0) mm++;

    int ct = 0;
    for (int i = 0; i < 110; i++) if (nc[i]) ct += mm - nc[i];
    cout << ct << "\n";
}