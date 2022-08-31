#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
const int MAXN = 100100;

int n;
double a, d;
double v[MAXN], t[MAXN];
double res[MAXN];

double solve (double vel)
{
    if (vel * vel / 2 / a >= d)
        return sqrt (d * 2 / a);
    return vel / a + (d - vel * vel / 2 / a) / vel;
}

int main()
{
    cin >> n >> a >> d;
    for (int i = 0; i < n; i++)
        cin >> t[i] >> v[i];
    for (int i = 0; i < n; i++)
        res[i] = solve (v[i]) + t[i];
    cout << fixed << setprecision(5);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && res[i] < res[i-1])
            res[i] = res[i-1];
        cout << res[i] << "\n";
    }
    //system ("Pause");
    return 0;
}