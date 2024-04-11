#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const int MAXP = (1 << 15);

int N, M, P;
ll v[MAXN];

ll ans;

int num[MAXP];

void figure (int cloc)
{
    for (int i = 0; i < MAXP; i++)
        num[i] = 0;

    vector <int> locs;
    for (int i = 0; i < M; i++)
        if (v[cloc] & (1LL << i))
            locs.push_back(i);

    //cout << cloc << "\n";
    for (int i = 0; i < N; i++)
    {
        ll tot = 0;
        for (int j = 0; j < locs.size(); j++)
            if (v[i] & (1LL << locs[j]))
                tot += (1LL << j);
        //cout << tot << "\n";
        num[tot]++;
    }
    //cout << "\n";

    int K = locs.size();
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < (1 << K); j++)
            if (j & (1 << i))
            {
                num[j - (1 << i)] += num[j];
            }
    }

    for (int i = 0; i < (1 << K); i++)
        if (num[i] * 2 >= N)
        {
            if (__builtin_popcountll(i) > __builtin_popcountll(ans))
            {
                ll tot = 0;
                for (int j= 0; j < K; j++)
                    if (i & (1 << j))
                        tot += (1LL << locs[j]);
                ans = tot;
            }
        }
}

void gogo()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> N >> M >> P;
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        v[i] = 0;
        for (int j = 0; j < M; j++)
        {
            v[i] = 2 * v[i] + (s[j] - '0');
        }
    }

    ans = 0;
    for (int i = 0; i < 22; i++)
    {
        figure(rng() % N);
    }

    for (int i = M - 1; i >= 0; i--)
    {
        if (ans & (1LL << i))
            cout << 1;
        else
            cout << 0;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T = 1;
    for (int t = 0; t < T; t++)
        gogo();
}