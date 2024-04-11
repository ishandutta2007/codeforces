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

char place (int x)
{
    cout << x << " " << 1 << endl;
    string s;
    cin >> s;
    return s[0];
}

int main()
{
    ios_base::sync_with_stdio(0);

    int N; cin >> N;
    char c = place (0);

    int lo = 1, hi = 1e9;
    for (int i = 1; i < N; i++)
    {
        int mid = (lo + hi) / 2;
        char d = place (mid);
        if (d == c)
        {
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    cout << lo - 1 << " " << 0 << " " << lo << " " << 2 << "\n";
}