#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N;
int l[MAXN], r[MAXN];
int pl[MAXN], pr[MAXN], sl[MAXN], sr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> l[i] >> r[i];
    }

    pl[0] = 0;
    pr[0] = 1e9;
    for (int i = 0; i < N; i++)
    {
        pl[i+1] = max (pl[i], l[i]);
        pr[i+1] = min (pr[i], r[i]);
    }

    sl[0] = 0;
    sr[0] = 1e9;
    for (int i = 0; i < N; i++)
    {
        sl[i+1] = max (sl[i], l[N-1-i]);
        sr[i+1] = min (sr[i], r[N-1-i]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int ll = max (pl[i], sl[N-1-i]);
        int rr = min (pr[i], sr[N-1-i]);
        ans = max (ans, rr - ll);
    }
    cout << ans << "\n";
}