#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const int P = (1 << 18);
const int MAXP = 2 * P + 100;

int N;
ll cv[MAXN];

ll seg[MAXP];
int ans[MAXN];

void upd (int cloc, int cadd)
{
    cloc += P;
    while (cloc)
    {
        seg[cloc] += cadd;
        cloc /= 2;
    }
}

int find_val (ll csum)
{
    int cloc = 1;
    while (cloc < P)
    {
        if (seg[2*cloc] <= csum)
        {
            csum -= seg[2*cloc];
            cloc = 2 * cloc + 1;
        }
        else
        {
            cloc = 2 * cloc;
        }
    }
    return cloc - P;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> cv[i];

    for (int i = 0; i < MAXP; i++)
        seg[i] = 0;
    for (int i = 1; i <= N; i++)
        upd (i, i);

    for (int i = N - 1; i >= 0; i--)
    {
        ans[i] = find_val (cv[i]);
        upd (ans[i], -ans[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}