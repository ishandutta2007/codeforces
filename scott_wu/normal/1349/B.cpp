#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 300100;
const int P = (1 << 18);
const int MAXP = 2 * P + 100;

int N, K;
int arr[MAXN];

int gg[MAXN];
int seg[MAXP];

ll ask (int cloc)
{
    cloc += P;
    ll res = 0;
    while (cloc > 1)
    {
        if (cloc & 1)
            res += seg[cloc-1];
        cloc /= 2;
    }
    return res;
}

void upd (int cloc, int v)
{
    cloc += P;
    seg[cloc] = v;
    while (cloc > 1)
    {
        cloc /= 2;
        seg[cloc] = seg[2*cloc] + seg[2*cloc+1];
    }
}

ll figure()
{
    for (int i = 0; i <= 2 * N + 5; i++)
        upd (i, 0);

    int cv = N;
    upd (cv, 1);

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        cv += gg[i];
        ans += (i + 1) - ask (cv + 1);
        upd (cv, seg[cv+P] + 1);
    }
    for (int i = 0; i <= 2 * N + 5; i++)
        upd (i, 0);
    return ans;
}

void gogo()
{
    cin >> N >> K;
    ll ng = 0, nt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] == K)
            ng++;
        if (arr[i] >= K)
            nt++;
    }

    if (ng == N)
    {
        cout << "yes\n";
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] <= K)
            gg[i] = 1;
        else
            gg[i] = -1;
    }
    ll v = figure();
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < K)
            gg[i] = 1;
        else
            gg[i] = -1;
    }
    ll vv = figure();
    
    if (ng > 0 && vv > nt)
        cout << "yes\n";
    else
        cout << "no\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}