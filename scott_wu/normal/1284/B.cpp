#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
vector <pair <int, int> > v;

int ncnt[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int K; cin >> K;
        int chi = 1e9;
        bool bad = false;

        int cstart = -1;
        for (int j = 0; j < K; j++)
        {
            int x; cin >> x;
            if (x > chi)
                bad = true;
            chi = x;

            if (j == 0) cstart = x;
        }

        if (!bad)
            v.push_back(make_pair (chi, cstart));
    }

    sort(v.begin(), v.end());
    for (auto pp : v)
        ncnt[pp.second]++;

    for (int i = 1; i < MAXN; i++)
        ncnt[i] += ncnt[i-1];

    ll res = 0;
    for (auto pp : v)
        res += ncnt[pp.first];
    cout << N * (ll) N - res << "\n";
}