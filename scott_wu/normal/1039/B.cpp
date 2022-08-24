#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
typedef long long ll;

ll N;
int K;

ll lo, hi;

void query (ll clo, ll chi)
{
    cout << clo << " " << chi << endl;
    string c;
    cin >> c;

    if (clo == chi && c[0] == 'Y')
        exit(0);

    if (lo == clo)
    {
        if (c[0] == 'Y')
            hi = chi;
        else
            lo = chi + 1;
    }
    lo = max (1LL, lo - K);
    hi = min (N, hi + K);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    lo = 1;
    hi = N;
    srand(time(NULL));
    while (true)
    {
        ll mid = (lo + hi) / 2;
        query (lo, mid);

        ll r = rand() % (hi - lo + 1);
        query (hi - r, hi - r);
    }
}