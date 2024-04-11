#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;

ll N;
int Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 0; i < Q; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        ll ncount = x * N + y;
        if ((x + y) % 2 == 0)
        {
            cout << ncount / 2 + 1 << "\n";
        }
        else
            cout << ncount / 2 + (N * N + 3) / 2 << "\n";
    }
}