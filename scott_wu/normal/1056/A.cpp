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
int nc[110];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < 110; i++)
        nc[i] = 0;
    for (int i = 0; i < N; i++)
    {
        int t; cin >> t;
        for (int j = 0; j < t; j++)
        {
            int x; cin >> x;
            nc[x]++;
        }
    }

    for (int i = 0; i < 110; i++)
        if (nc[i] == N)
            cout << i << " ";
    cout << "\n";
}