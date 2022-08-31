#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const long long MOD = 1000000007;
const double EPS = 1e-9;

int n;
ll l, v1, v2;
int choc[MAXN];
pair <double, bool> event[2*MAXN];
double ans[MAXN];

double mod (double x, double y)
{
    while (x > y)
        x -= y;
    return x;
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        ans[i] = 0.0;
    cin >> n >> l >> v1 >> v2;
    double len = ((double) v2 * (double) l) / ((double) v1 + (double) v2);
    for (int i = 0; i < n; i++)
    {
        cin >> choc[i];
        event[2*i] = make_pair (mod ((choc[i] + 2 * l - len), 2 * l), true);
        event[2*i+1] = make_pair ((double) choc[i], false);
    }
    sort (event, event + 2 * n);
    event[2*n] = make_pair (2*l, true);
    int slope = 0;
    for (int i = 0; i < n; i++)
        if ((double) choc[i] < len + EPS)
            slope++;
    double last = 0.0;
    for (int i = 0; i <= 2 * n; i++)
    {
        ans[slope] += (event[i].first - last) / (2 * (double) l);
        if (event[i].second)
            slope++;
        else
            slope--;
        last = event[i].first;
    }
    cout << fixed << setprecision (9);
    for (int i = 0; i <= n; i++)
        cout << ans[i] << "\n";
    //system ("Pause");
    return 0;
}