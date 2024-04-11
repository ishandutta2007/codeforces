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
const int MAXN = 1100;

int N;
bool nuse[MAXN];
int nc[MAXN];
pair <int, int> e[MAXN];
int M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y; cin >> x >> y;
        x--, y--;
        if (!((x == N - 1) ^ (y == N - 1)))
        {
            cout << "NO\n";
            return 0;
        }
        nc[x+y-(N-1)]++;
    }

    int cloc = N - 2;
    for (int i = N - 2; i >= 0; i--)
    {
        //cout << i << " " << nc[i] << endl;
        if (nc[i])
        {
            int ccnt = nc[i] - 1;
            int nprev = N - 1;
            while (ccnt)
            {
                if (cloc < 0)
                {
                    cout << "NO\n";
                    return 0;
                }
                if (!nuse[cloc] && !nc[cloc])
                {
                    if (cloc > i)
                    {
                        cout << "NO\n";
                        return 0;
                    }
                    e[M++] = make_pair (nprev, cloc);
                    nprev = cloc;
                    ccnt--;
                }
                cloc--;
            }
            e[M++] = make_pair (nprev, i);
        }
    }

    cout << "YES\n";
    for (int i = 0; i < N - 1; i++)
    {
        cout << e[i].first + 1 << " " << e[i].second + 1 << "\n";
    }
}