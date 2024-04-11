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
    int N;
    string s;
    cin >> N >> s;
    for (int i = 0; i <= 1000; i++)
    {
        int cs = 0, nn = 0;
        bool bad = false;
        for (int j = 0; j < N; j++)
        {
            cs += (s[j] - '0');
            if (cs >= i)
            {
                if (cs > i)
                    bad = true;
                cs = 0;
                nn++;
            }
        }
        if (cs > 0) bad = true;
        if (bad) continue;
        if (nn < 2) continue;
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
}