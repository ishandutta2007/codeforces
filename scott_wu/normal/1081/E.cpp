#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
vector <ll> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    N /= 2;

    int nlast = 0;
    ans.push_back(0);
    bool bad = false;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        int ares = -1, bres = -1;
        for (int j = 1; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                int nj = x / j;
                if ((j + nj) % 2 == 0)
                {
                    int a = (j + nj) / 2, b = (nj - j) / 2;
                    if (b > nlast)
                    {
                        ares = a;
                        bres = b;
                    }
                }
            }
        }
        if (ares == -1)
            bad = true;
        else
        {
            ans.push_back(bres);
            ans.push_back(ares);
            nlast = ares;
        }
    }

    if (bad)
        cout << "No\n";
    else
    {
        cout << "Yes\n";
        for (int i = 0; i < 2 * N; i++)
        {
            if (i) cout << " ";
            cout << ans[i+1] * ans[i+1] - ans[i] * ans[i];
        }
        cout << "\n";
    }
}