#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
string a, b;

int main()
{
    cin >> N >> a >> b;
    double tot = 0.0;
    for (int ch = 0; ch < 26; ch++)
    {
        char goal = (char) ('A' + ch);
        ll num = 0, num2 = 0, sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (a[i] == goal)
                num++;
            if (b[i] == goal)
            {
                num2++;
                sum += i;
            }
        }
        double res = 0.0;
        ll lsum = 0;
        ll hsum = N * num2 - sum;
        int nless = 0;
        for (int i = 0; i < N; i++)
        {
            if (a[i] == goal)
                res += (i + 1) * hsum + (N - i) * lsum;
            if (b[i] == goal)
            {
                hsum -= (N - i);
                lsum += i + 1;
            }
        }
        //cout << res << "\n";
        tot += res;
    }
    double den = ((ll) N * ((ll) N + 1) * (2 * (ll) N + 1)) / 6.0;
    cout << fixed << setprecision (7);
    cout << tot / den << "\n";
    //system ("Pause");
    return 0;
}