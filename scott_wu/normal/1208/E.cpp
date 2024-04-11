#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N, W;
ll res[MAXN];
ll hdiff[MAXN];

int M;
vector <int> v;

void range_add (int lo, int hi, int x)
{
    hdiff[lo] += x;
    hdiff[hi+1] -= x;
}

void roll()
{
    cin >> M;
    v.clear();
    for (int i = 0; i < M; i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }

    int bloc = 0;
    for (int i = 0; i < M; i++)
        if (v[i] > v[bloc])
        {
            bloc = i;
        }

    if (M * 2 <= W)
    {
        if (v[bloc] <= 0) return;
        range_add (bloc, (W - M) + bloc, v[bloc]); // inclusive
        int cres = 0;
        for (int i = 0; i < bloc; i++)
        {
            cres = max (cres, v[i]);
            res[i] += cres;
        }
        cres = 0;
        for (int i = M - 1; i > bloc; i--)
        {
            cres = max (cres, v[i]);
            res[(W-M)+i] += cres;
        }
        return;
    }

    vector <pair <int, int> > q;
    q.push_back (make_pair (-1, 0));
    int qs = 0;

    for (int i = 0; i < W; i++)
    {
        if (i < M)
        {
            pair <int, int> np;
            np.first = i;
            np.second = v[i];
            while ((int) q.size() > qs && q.back().second <= np.second)
            {
                q.pop_back();
            }
            q.push_back (np);
        }
        while ((int) q.size() > qs && q[qs].first < (i - (W - M)))
            qs++;

        int ans = -1e9;
        if ((int) q.size() > qs)
            ans = q[qs].second;
        if (i >= M) ans = max (ans, 0);
        res[i] += ans;

        //cout << i << " " << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < MAXN; i++)
        res[i] = hdiff[i] = 0;

    cin >> N >> W;
    for (int i = 0; i < N; i++)
    {
        roll();
    }

    ll cdiff = 0;
    for (int i = 0; i < W; i++)
    {
        cdiff += hdiff[i];
        res[i] += cdiff;
    }

    for (int i = 0; i < W; i++)
    {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}