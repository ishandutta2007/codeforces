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
    int N, D, M;
    cin >> N >> D >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x + y >= D && x + y <= 2 * N - D && x - y <= D && y - x <= D)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}