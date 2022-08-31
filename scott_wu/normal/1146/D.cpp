#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N;
int M, A, B; // + a or - b
int G;

bool seen[MAXN];
int cdist[MAXN];
priority_queue <pair <int, int> > q;

int gcf (int a, int b)
{
    if (b == 0) return a;
    return gcf (b, a % b);
}

void gogo()
{
    for (int i = 0; i < MAXN; i++)
    {
        seen[i] = false;
        cdist[i] = 1e9;
    }
    cdist[0] = 0;
    q.push(make_pair (0, 0));

    while (!q.empty())
    {
        pair <int, int> p = q.top();
        q.pop();
        int cloc = p.second, cval = -p.first;
        if (seen[cloc]) continue;
        seen[cloc] = true;

        if (cloc + A <= N)
        {
            int nloc = cloc + A;
            int nval = max (cval, nloc);
            if (cdist[nloc] > nval)
            {
                cdist[nloc] = nval;
                q.push(make_pair(-nval, nloc));
            }
        }
        if (cloc >= B)
        {
            int nloc = cloc - B;
            int nval = cval;
            if (cdist[nloc] > nval)
            {
                cdist[nloc] = nval;
                q.push(make_pair(-nval, nloc));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> M >> A >> B;

    G = gcf (A, B);
    N = A + B + 4;
    while (N % G != 0)
        N++;
    N--;

    gogo();
    /*cout << N << endl;
    for (int i = 0; i <= N; i++)
        cout << cdist[i] << " ";
    cout << "\n";*/

    ll ans = 0;
    if (N >= M)
    {
        for (int i = 0; i <= M; i++)
        {
            ans += max (0, (M + 1 - cdist[i]));
        }
    }
    else
    {
        for (int i = 0; i <= N; i++)
        {
            ans += max (0, (N + 1 - cdist[i]));
        }
        // sum of 0..N
        N++;
        ll nlo = N / G, nhi = M / G;
        ll v = ((nhi * (nhi - 1)) - (nlo * (nlo - 1))) / 2 * G;
        ans += v;
        ans += (nhi - nlo) * G;
        N = nhi * G;
        while (N <= M)
        {
            ans += (N / G) + 1;
            N++;
        }
    }
    cout << ans << "\n";
}