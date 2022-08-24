#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

ll K, D, T;

int main()
{
    cin >> K >> D >> T;
    if (K % D == 0)
    {
        cout << T << "\n";
        return 0;
    }
    ll lround = K % D;

    double ncook = K / (double) T + (D - lround) / (double) T / 2.;

    //cout << ncook << " " << nless << "\n";

    ll nround = 1. / ncook;
    double ntime = nround * (K + D - lround);
    double nleft = 1. - nround * ncook;

    if (nleft < K / (double) T)
        ntime += nleft * T;
    else
    {
        ntime += K;
        nleft -= K / (double) T;
        ntime += nleft * 2 * T;
    }
    cout << fixed << setprecision(10);
    cout << ntime << "\n";
}