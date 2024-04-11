#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N;
int x[MAXN], y[MAXN];
int xc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int yc[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int mbest[8];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 0; i < 8; i++)
        mbest[i] = -1e9;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i];
        for (int j = 0; j < 8; j++)
        {
            int cs = x[i] * xc[j] + y[i] * yc[j];
            mbest[j] = max (mbest[j], cs);
        }
    }

    int r3 = -1e9, r4 = 0;
    for (int i = 0; i < 4; i++)
        r4 += mbest[2*i];
    for (int i = 0; i < 4; i++)
    {
        int a = 2 * i, b = (2 * i + 2) % 8, c = (2 * i + 5) % 8;
        r3 = max (r3, mbest[a] + mbest[b] + mbest[c]);
    }
    r3 = 2 * r3;
    r4 = 2 * r4;

    cout << r3;
    for (int i = 4; i <= N; i++)
        cout << " " << r4;
    cout << "\n";
}