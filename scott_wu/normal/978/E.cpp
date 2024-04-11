#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, W;
int arr[MAXN];

int main()
{
    cin >> N >> W;
    int lo = 0, hi = 0;
    int csum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        csum += arr[i];
        lo = min (lo, csum);
        hi = max (hi, csum);
    }

    int span = hi - lo + 1;
    if (span > W + 1)
    {
        cout << "0\n";
    }
    else
    {
        cout << W + 2 - span << "\n";
    }
}