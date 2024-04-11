#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
ll v[MAXN];
int deg[MAXN];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        deg[i] = 0;

    ll tot = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        tot += v[i];
    }

    vector <ll> ext;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        deg[x]++;
        deg[y]++;
    }

    for (int i = 0; i < N; i++)
        for (int j = 1; j < deg[i]; j++)
            ext.push_back(v[i]);
    sort (ext.begin(), ext.end());

    cout << tot;
    for (int i = ext.size() - 1; i >= 0; i--)
    {
        tot += ext[i];
        cout << " " << tot;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}