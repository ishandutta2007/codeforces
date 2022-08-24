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

    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        for (int j = 0; j < n; j++)
            cout << (char) (j % k + 'a');
        cout << "\n";
    }
}