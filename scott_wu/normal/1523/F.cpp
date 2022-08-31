#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 15;
const int MAXP = (1 << 14);
const int MAXM = 110;

int N, M;
pair <ll, ll> nloc[MAXN];
pair <ll, ll> mloc[MAXM];
ll mtime[MAXM];

ll ndist[MAXP][MAXN];
ll mdist[MAXP][MAXM];

bool seen[MAXP][MAXM];
ll dscore[MAXP][MAXM];
ll dloc[MAXP][MAXM];

priority_queue <pair <ll, pair <int, int> > > pq; // time, subset, (score / loc + MAXM)

void dijk()
{
    for (int i = 0; i < MAXP; i++)
    {
        for (int j = 0; j < MAXM; j++)
        {
            dscore[i][j] = 2e9;
            dloc[i][j] = -1e9;
            seen[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        dscore[(1<<i)][0] = 0;
        pq.push (make_pair (0, make_pair ((1 << i), 0)));
    }
    for (int i = 0; i < M; i++)
    {
        dloc[0][i] = 1;
        for (int j = 0; j < (1 << N); j++)
            pq.push (make_pair (-mtime[i], make_pair (j, i + MAXM)));
    }

    while (!pq.empty())
    {
        ll t = -pq.top().first;
        int mask = pq.top().second.first;
        int v = pq.top().second.second;

        pq.pop();

        if (v >= MAXM)
        {
            v -= MAXM;
            if (dloc[mask][v] < 0) continue;
            //cout << "LOC ";
            //cout << t << " " << mask << " " << v << " " << dloc[mask][v] << "\n";

            int cscore = dloc[mask][v];
            if (dscore[mask][cscore] > t)
            {
                dscore[mask][cscore] = t;
                pq.push (make_pair (-t, make_pair (mask, cscore)));
            }
            for (int i = 0; i < N; i++)
            {
                if (!(mask & (1 << i)))
                {
                    ll d = abs (nloc[i].first - mloc[v].first) + abs (nloc[i].second - mloc[v].second);
                    ll nt = t + d;
                    ll nmask = mask + (1 << i);
                    if (nt < dscore[nmask][cscore])
                    {
                        dscore[nmask][cscore] = nt;
                        pq.push (make_pair (-nt, make_pair (nmask, cscore)));
                    }
                }
            }
            for (int i = 0; i < M; i++)
            {
                if (i == v) continue;
                if (mtime[i] < t) continue;
                ll d = abs (mloc[i].first - mloc[v].first) + abs (mloc[i].second - mloc[v].second);
                ll nt = t + d;
                if (nt <= mtime[i])
                    dloc[mask][i] = max (dloc[mask][i], (ll) cscore + 1);
            }
        }
        else
        {
            if (seen[mask][v]) continue;
            seen[mask][v] = true;
            if (t > 1e9) continue;

            for (int i = 0; i < N; i++)
            {
                if (!(mask & (1 << i)))
                {
                    ll nt = ndist[mask][i] + t;

                    int nmask = mask + (1 << i);
                    if (nt < dscore[nmask][v])
                    {
                        dscore[nmask][v] = nt;
                        pq.push (make_pair (-nt, make_pair (nmask, v)));
                    }
                }
            }
            for (int i = 0; i < M; i++)
            {
                if (mtime[i] < t) continue;
                ll nt = t + mdist[mask][i];
                if (nt <= mtime[i])
                    dloc[mask][i] = max (dloc[mask][i], (ll) v + 1);
            }
        }
    }
}

void gogo()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> nloc[i].first >> nloc[i].second;
    for (int i = 0; i < M; i++)
        cin >> mloc[i].first >> mloc[i].second >> mtime[i];

    for (int i = 0; i < (1 << N); i++)
    {
        for (int j = 0; j < N; j++)
        {
            ll res = 1e9;
            for (int k = 0; k < N; k++)
                if (i & (1 << k))
                {
                    res = min (res, abs(nloc[k].first - nloc[j].first) + abs (nloc[k].second - nloc[j].second));
                }
            ndist[i][j] = res;
        }
        for (int j = 0; j < M; j++)
        {
            ll res = 1e9;
            for (int k = 0; k < N; k++)
                if (i & (1 << k))
                {
                    res = min (res, abs(nloc[k].first - mloc[j].first) + abs (nloc[k].second - mloc[j].second));
                }
            mdist[i][j] = res;
        }
    }

    dijk();

    ll ans = 0;
    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < M; j++)
            ans = max (ans, dloc[i][j]);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T = 1;
    for (int t = 0; t < T; t++)
        gogo();
}