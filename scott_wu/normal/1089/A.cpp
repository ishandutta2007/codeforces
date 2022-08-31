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
const int MAXD = 300;

bool works[MAXD][MAXD][4][4];
pair <int, int> nlast[MAXD][MAXD][4][4];

pair <int, int> pp[6];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    for (int i = 0; i < MAXD; i++)
        for (int j = 0; j < MAXD; j++)
            for (int k = 0; k < 4; k++)
                for (int l = 0; l < 4; l++)
                {
                    works[i][j][k][l] = false;
                    nlast[i][j][k][l] = make_pair (0, 0);
                }

    pp[0] = make_pair (3, 0);
    pp[1] = make_pair (3, 1);
    pp[2] = make_pair (3, 2);
    pp[3] = make_pair (2, 3);
    pp[4] = make_pair (1, 3);
    pp[5] = make_pair (0, 3);

    works[0][0][0][0] = true;
    for (int g = 1; g <= 5; g++)
    {
        int GOAL = 25;
        if (g == 5) GOAL = 15;
        for (int x = 0; x <= 3; x++)
        {
            int y = g - x;
            if (x > g || y > g || y > 3) continue;
            for (int i = 0; i < MAXD; i++)
                for (int j = 0; j < MAXD; j++)
                {
                    // figure out [i][j][x][y]
                    if (x && y < 3)
                    {
                        for (int k = 0; k <= j; k++)
                        {
                            int nk = max (GOAL, k + 2);
                            if (nk > i) break;
                            if (works[i-nk][j-k][x-1][y])
                            {
                                works[i][j][x][y] = true;
                                nlast[i][j][x][y] = make_pair (nk, k);
                                break;
                            }
                        }
                    }
                    if (works[i][j][x][y]) continue;
                    if (y && x < 3)
                    {
                        for (int k = 0; k <= i; k++)
                        {
                            int nk = max (GOAL, k + 2);
                            if (nk > j) break;
                            if (works[i-k][j-nk][x][y-1])
                            {
                                works[i][j][x][y] = true;
                                nlast[i][j][x][y] = make_pair (k, nk);
                                break;
                            }
                        }
                    }
                }
        }
    }

    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        bool found = false;
        for (int j = 0; j < 6; j++)
        {
            int x = pp[j].first, y = pp[j].second;
            if (works[a][b][x][y])
            {
                cout << x << ":" << y << "\n";
                vector <pair <int, int> > v;
                while (x + y > 0)
                {
                    v.push_back(nlast[a][b][x][y]);
                    a -= v.back().first;
                    b -= v.back().second;
                    if (v.back().first > v.back().second)
                        x--;
                    else
                        y--;
                }
                reverse (v.begin(), v.end());
                for (int n = 0; n < v.size(); n++)
                {
                    if (n) cout << " ";
                    cout << v[n].first << ":" << v[n].second;
                }
                cout << "\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "Impossible\n";
    }
}