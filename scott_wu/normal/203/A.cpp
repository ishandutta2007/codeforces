#include <iostream>

using namespace std;

int cost[2][310];

int x, t, a, b, c, d;

int main()
{
    cin >> x >> t >> a >> b >> c >> d;
    cost[0][0] = a;
    for (int i = 1; i < t; i++)
        cost[0][i] = max (cost[0][i-1] - c, 0);
    cost[1][0] = b;
    for (int i = 1; i < t; i++)
        cost[1][i] = max (cost[1][i-1] - d, 0);
    cost[0][t] = cost[1][t] = 0;
    bool check = false;
    for (int i = 0; i <= t; i++)
        for (int j = 0; j <= t; j++)
            if (cost[0][i] + cost[1][j] == x)
                check = true;
    cout << ((check) ? "YES\n" : "NO\n");
    //system ("Pause");
    return 0;
}