#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, M;
char c[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> c[i];
    sort (c, c + N);

    char cloc = 'a' - 5;
    int res = 0, ncnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (c[i] > cloc + 1)
        {
            cloc = c[i];
            ncnt++;
            res += c[i] - 'a' + 1;
            if (ncnt == M)
                break;
        }
    }

    if (ncnt < M)
    {
        cout << "-1\n";
        return 0;
    }
    cout << res << "\n";
}