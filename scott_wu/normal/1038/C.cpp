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

int N;
int v[200100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    ll tot = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> v[i];
        if (i < N)
            tot += v[i];
        else
            tot -= v[i];
    }
    sort (v, v + 2 * N);
    for (int i = 0; i < 2 * N; i += 2)
        tot += v[i+1] - v[i];
    cout << tot / 2 << "\n";
}