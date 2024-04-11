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
const int MAXN = 100100;

int N;
int l[MAXN], r[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> l[i] >> r[i];
    sort (l, l + N);
    sort (r, r + N);

    ll ans = N;
    for (int i = 0; i < N; i++)
        ans += max (l[i], r[i]);
    cout << ans << "\n";
}