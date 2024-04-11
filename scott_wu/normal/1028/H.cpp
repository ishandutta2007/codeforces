#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const int MAXD = 5100000;
const int MAXP = 8;

int N, Q;
int arr[MAXN];
vector <pair <int, int> > q[MAXN];
int ans[6*MAXN];
int pp[MAXD];
int last_seen[MAXD][MAXP];
int last_val[2*MAXP];

vector <int> fac;
int ccur;

void flood (int cloc, int cc, int ntake)
{
    if (cloc == fac.size())
    {
        //cout << ccur << " " << cc << " " << ntake << "\n";
        for (int i = 0; i < MAXP; i++)
        {
            last_val[i+ntake] = max (last_val[i+ntake], last_seen[cc][i]);
        }
        last_seen[cc][ntake] = ccur;
        return;
    }
    flood (cloc + 1, cc * fac[cloc], ntake - 1);
    flood (cloc + 1, cc, ntake);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        q[y].push_back(make_pair (x, i));
    }

    for (int i = 0; i < MAXD; i++)
    {
        pp[i] = -1;
        for (int j = 0; j < MAXP; j++)
            last_seen[i][j] = -1;
    }
    for (int i = 0; i < 2 * MAXP; i++)
        last_val[i] = -1;
    for (int i = 2; i < MAXD; i++)
    {
        if (pp[i] == -1)
        {
            pp[i] = i;
            for (int j = i; j < MAXD; j += i)
                pp[j] = i;
        }
    }

    for (int i = 0; i < N; i++)
    {
        ccur = i;
        fac.clear();
        int cc = arr[i];
        while (cc > 1)
        {
            int p = pp[cc];
            int cnt = 0;
            while (cc % p == 0)
            {
                cc /= p;
                cnt++;
            }
            if (cnt & 1) fac.push_back(p);
        }

        flood (0, 1, fac.size());
        for (int j = 0; j < q[i].size(); j++)
        {
            int ind = q[i][j].second, start = q[i][j].first;
            for (int k = 0; k < 2 * MAXP; k++)
                if (last_val[k] >= start)
                {
                    ans[ind] = k;
                    break;
                }
        }
    }

    for (int i = 0; i < Q; i++)
        cout << ans[i] << "\n";
}