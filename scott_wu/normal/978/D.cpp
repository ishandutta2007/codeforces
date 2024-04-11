#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
ll arr[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    if (N <= 2)
    {
        cout << "0\n";
        return 0;
    }

    int bval = 1e9;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            bool good = true;
            ll a = arr[0] + i;
            ll b = arr[1] + j;
            ll diff = b - a;

            int nshift = 0;
            for (int k = 0; k < N; k++)
            {
                ll nv = a + diff * k;
                if (abs(nv - arr[k]) >= 2)
                    good = false;
                if (abs(nv - arr[k]) == 1)
                    nshift++;
            }
            if (!good)
                continue;
            bval = min (bval, nshift);
        }
    }

    if (bval > N)
        cout << "-1\n";
    else
        cout << bval << "\n";
}