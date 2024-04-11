#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef unsigned long long ll;

ll p10[20];
map <ll, int> mm;

int main()
{
    ios_base::sync_with_stdio(0);
    p10[0] = 1;
    for (int i = 1; i < 20; i++)
        p10[i] = p10[i-1] * 10;

    for (int i = 0; i <= 18; i++)
    {
        for (int j = i + 1; j <= 18; j++)
        {
            for (int k = j + 1; k <= 18; k++)
            {
                for (int m = 0; m < 1000; m++)
                {
                    ll cv = p10[i] * (m % 10) + p10[j] * ((m / 10) % 10) + p10[k] * (m / 100);
                    mm[cv] = 0;
                }
            }
        }
    }

    int ctot = 0;
    for (auto it = mm.begin(); it != mm.end(); it++)
        it->second = ctot++;

    int T; cin >> T;
    ll L, R;
    for (int i = 0; i < T; i++)
    {
        cin >> L >> R;
        cout << mm.lower_bound(R+1)->second - mm.lower_bound(L)->second << "\n";
    }
}