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
typedef long double ld;

int T, N;

void answer (ld x, ld y)
{
    cout << "Y " << x << " " << y << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cout << fixed << setprecision(9);

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        if (N == 0)
        {
            answer (0., 0.);
            continue;
        }
        else if (N <= 3)
        {
            cout << "N\n";
            continue;
        }

        ld d = N;
        ld df = sqrt(d * d - 4 * d);
        answer ((d - df) / 2., (d + df) / 2.);
    }
}