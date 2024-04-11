#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
vector <int> vc[MAXN];
int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        vc[N-x].push_back(i);
    }

    bool bad = false;
    int nc = 0;
    for (int i = 1; i <= N; i++)
    {
        if (vc[i].size() % i != 0)
            bad = true;
        else
        {
            for (int j = 0; j < vc[i].size(); j++)
            {
                if (j % i == 0)
                {
                    nc++;
                }
                ans[vc[i][j]] = nc;
            }
        }
    }

    if (bad)
    {
        cout << "Impossible\n";
    }
    else
    {
        cout << "Possible\n";
        for (int i = 0; i < N; i++)
        {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
}