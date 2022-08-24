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
const int MAXN = 100;

int M, N;
int arr[MAXN];

int ask (int x)
{
    cout << x << "\n" << flush;
    int c; cin >> c;
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> M >> N;
    int lo = 1, hi = M;
    for (int i = 0; i < N; i++)
    {
        arr[i] = ask (1);
        if (arr[i] == 0)
            return 0;
    }

    int cc = 0;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        int m = ask(mid);
        if (m == 0)
            return 0;

        if (m * arr[cc % N] == 1)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
        cc++;
    }
    ask (lo);
}