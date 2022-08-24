#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
const int MAXN = 55;

int N;
pair <int, int> p[MAXN];

bool good (int k)
{
    int xlo = 1000, ylo = 1000, xhi = -1000, yhi = -1000;
    for (int i = 0; i < N; i++)
    {
        if (i == k) continue;
        xlo = min (xlo, p[i].first);
        xhi = max (xhi, p[i].first);
        ylo = min (ylo, p[i].second);
        yhi = max (yhi, p[i].second);
    }

    if (xhi - xlo != yhi - ylo)
        return false;
    for (int i = 0; i < N; i++)
    {
        if (i == k) continue;
        if (p[i].first != xlo &&
            p[i].first != xhi &&
            p[i].second != ylo &&
            p[i].second != yhi)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    N = 4 * N + 1;
    for (int i = 0; i < N; i++)
        cin >> p[i].first >> p[i].second;
    for (int i = 0; i < N; i++)
    {
        if (good (i))
        {
            cout << p[i].first << " " << p[i].second << "\n";
            return 0;
        }
    }
}