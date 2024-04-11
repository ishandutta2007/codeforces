#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 110;

int N;
int L[MAXN], R[MAXN], val[MAXN];

int p[4], par[4];

void uni (int left, int right)
{
    int pl = par[left], pr = par[right];
    for (int i = 0; i < 4; i++)
        if (par[i] == pl)
            par[i] = pr;
}

bool works (vector <int> l, vector <int> r)
{
    for (int i = 0; i < 4; i++)
    {
        p[i] = 0;
        par[i] = i;
    }

    for (int i = 0; i < l.size(); i++)
    {
        p[l[i]]++;
        p[r[i]]++;
        uni (l[i], r[i]);
    }

    int pv = -1;
    int c = 0;
    for (int i = 0; i < 4; i++)
    {
        if (p[i] > 0)
        {
            if (pv == -1) pv = par[i];
            else if (par[i] != pv) return false;
        }
        if (p[i] % 2 == 1) c++;
    }
    return c <= 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> L[i] >> val[i] >> R[i];
        L[i]--, R[i]--;
    }

    int ans = 0;
    for (int skip = 0; skip <= N; skip++)
    {
        for (int cn = 0; cn < 16; cn++)
        {
            vector <int> l, r;
            int vtot = 0;
            for (int i = 0; i < N; i++)
            {
                if (i == skip) continue;
                if (cn & (1 << L[i])) continue;
                if (cn & (1 << R[i])) continue;
                l.push_back(L[i]);
                r.push_back(R[i]);
                vtot += val[i];
            }

            if (works (l, r))
                ans = max (ans, vtot);
        }
    }
    cout << ans << "\n";
}