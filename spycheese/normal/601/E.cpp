#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < int , int > ipair;

const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int N = 50179;
const int T = 1 << 15;
const int W = 1001;
const int MOD = 1234567;

int n, k;
int sc[N], sw[N];
int startm[N];
ll dd[W];

vector < ipair > st[T*2-1];
int cur;

void addEv(int l, int r, ipair rv, int c = 0, int cl = 0, int cr = T - 1)
{
    if (l > cr || r < cl)
        return;
    if (l <= cl && cr <= r)
    {
        st[c].push_back(rv);
        return;
    }
    addEv(l, r, rv, c*2+1, cl, (cl+cr)/2);
    addEv(l, r, rv, c*2+2, (cl+cr)/2+1, cr);
}


void go(int tc, int tl = 0, int tr = T - 1)
{
    ll prev[W];
    memcpy(prev, dd, sizeof(dd));
    for (auto x : st[tc])
        for (int i = W - 1 - x.second; i >= 0; --i)
            dd[i + x.second] = max(dd[i + x.second], dd[i] + x.first);
    if (tl == tr)
    {
        if (tl < cur)
        {
            ll cans = 0;
            ll ppow = 1;
            for (int m = 1; m <= k; ++m)
            {
                (cans += dd[m]*ppow) %= 1000000007;
                (ppow *= 10000019) %= 1000000007;
            }
            cout << cans << "\n";
        }
    } else {
        go(tc*2+1, tl, (tl+tr)/2);
        go(tc*2+2, (tl+tr)/2+1, tr);
    }
    memcpy(dd, prev, sizeof(prev));
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> sc[i] >> sw[i];

    int q;
    cin >> q;
    int cn = n;
    for (int i = 0; i < q; ++i)
    {
        int ev;
        cin >> ev;
        if (ev == 1)
        {
            cin >> sc[cn] >> sw[cn];
            startm[cn++] = cur;
        }
        else if (ev == 2)
        {
            int nn;
            cin >> nn;
            --nn;
            if (startm[nn] <= cur - 1)
            {
                addEv(startm[nn], cur - 1, ipair(sc[nn], sw[nn]));
            }
            startm[nn] = -1;
        } else
            ++cur;
    }
    for (int i = 0; i < cn; ++i)
        if (startm[i] != -1)
            addEv(startm[i], cur - 1, ipair(sc[i], sw[i]));

    go(0);

    return 0;
}