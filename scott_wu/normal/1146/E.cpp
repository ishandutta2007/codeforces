#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const int P = (1 << 17);
const int MAXP = 2 * P + 100;

int N, Q;
int arr[MAXN];
int qv[MAXN];
int qdir[MAXN]; // 1 for >, 0 for <
int qres[MAXN]; // 0 = no change, 1 = flip, 2 = -, 3 = +
int ares[MAXN]; // 0 = no change, 1 = flip, 2 = -, 3 = +
vector <int> looks[MAXN];

set <int> s;
int seg[MAXP];

void upd (int cloc, int v)
{
    cloc += P;
    seg[cloc] = v;
    while (cloc)
    {
        cloc /= 2;
        seg[cloc] = (seg[2*cloc] + seg[2*cloc+1]);
    }
}

int get_sum (int cloc)
{
    cloc += P;
    int res = 0;
    while (cloc > 1)
    {
        if (cloc & 1)
            res += seg[cloc-1];
        cloc /= 2;
    }
    return res % 2;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> Q;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = Q - 1; i >= 0; i--)
    {
        char ch; cin >> ch >> qv[i];
        if (ch == '>')
            qdir[i] = 1;
        else
            qdir[i] = 0;
        for (int j = -1; j <= 1; j++)
        {
            looks[abs (qv[i] + j)].push_back(i);
        }
    }
    for (int i = 0; i < Q; i++)
        looks[0].push_back(i);

    for (int i = 0; i < MAXP; i++)
        seg[i] = 0;

    for (int i = 0; i < MAXN; i++)
    {
        for (int j : looks[i])
        {
            if (qdir[j])
            {
                if (qv[j] < -i)
                    qres[j] = 1;
                else if (qv[j] < i)
                    qres[j] = 2;
                else
                    qres[j] = 0;
            }
            else
            {
                if (qv[j] > i)
                    qres[j] = 1;
                else if (qv[j] > -i)
                    qres[j] = 3;
                else
                    qres[j] = 0;
            }
            s.erase(j);
            if (qres[j] == 2 || qres[j] == 3)
                s.insert(j);
            int sv = 0;
            if (qres[j] == 1)
                sv = 1;
            upd (j, sv);
        }

        if (!s.empty())
        {
            int ev = *s.begin();
            ares[i] = qres[ev];
            if (get_sum (ev))
                ares[i] ^= 1;
        }
        else
        {
            ares[i] = get_sum (Q);
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        int ans;

        int acur = abs (arr[i]);
        int qcur = ares[acur];
        if (qcur == 0)
            ans = arr[i];
        else if (qcur == 1)
            ans = -arr[i];
        else if (qcur == 2)
            ans = -acur;
        else
            ans = acur;
        cout << ans;
    }
    cout << "\n";
}