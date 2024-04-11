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

int N;
int lo, hi; // where a new book will be placed
map <int, int> mm;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    lo = 0;
    hi = 1;
    for (int i = 0; i < N; i++)
    {
        char c; cin >> c;
        int id; cin >> id;

        if (c == 'L')
        {
            mm[id] = lo;
            lo--;
        }
        else if (c == 'R')
        {
            mm[id] = hi;
            hi++;
        }
        else
        {
            cout << min (mm[id] - lo - 1, hi - mm[id] - 1) << "\n";
        }
    }
}