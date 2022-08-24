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

int Y, A, B;
int N;
map <int, int> mm;

double query (double x)
{
    auto it = mm.upper_bound(x);
    double rx = it->first, rtot = it->second;
    it--;
    double lx = it->first, ltot = it->second;
    //cout << lx << " " << x << " " << rx << "\n";
    //cout << rtot << " " << ltot << "\n";
    //cout << (((x - lx) * rtot) + ((rx - x) * ltot)) / (rx - lx) << "\n"; 
    return (((x - lx) * rtot) + ((rx - x) * ltot)) / (rx - lx);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> Y >> A >> B;
    Y = -Y;
    cin >> N;
    int ntot = 0;
    for (int i = 0; i < N; i++)
    {
        int l, r;
        cin >> l >> r;
        mm[l] = ntot;
        ntot += r - l;
        mm[r] = ntot;
    }
    mm[-2e9] = 0;
    mm[2e9] = ntot;

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int x, y; cin >> x >> y;
        double lo, hi;
        lo = (y * (double) A + Y * (double) x) / (y + (double) Y);
        hi = (y * (double) B + Y * (double) x) / (y + (double) Y);

        double res = (query (hi) - query (lo)) / (hi - lo) * ((double) B - A);
        printf("%.8lf\n", res);
    }
}