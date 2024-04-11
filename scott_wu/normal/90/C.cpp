#include <iostream>

using namespace std;

const int MAXN = 10100;

long long list[MAXN];
bool good[MAXN];

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    for (int a = 0; a < n; a++)
        cin >> list[a];
    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
            if (good[b] || list[b])
            {
                good[b] = true;
                if (b % 2 == 0)
                    good[b+1] = true;
                else
                    good[b-1] = true;
            }
    long long best = 100000000;
    for (int a = 0; a < n; a+=2)
        best = min (best, list[a]);
    /*bool check = true, check2 = true;
    for (int a = 0; a < n; a+= 2)
        if (!good[a])
            check = false;
    for (int a = 1; a < n; a+= 2)
        if (!good[a])
            check2 = false;*/
    if (n % 2 == 1)
        cout << min (m / ((n + 1) / 2) * k, best) << "\n";
    else
        cout << "0\n";
    return 0;
}