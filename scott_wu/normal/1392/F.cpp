#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
ll HT;
ll H[MAXN];
vector <int> vspec;

ll res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    HT = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
        HT += H[i];
    }

    ll chi = H[0];
    for (int i = 1; i < N; i++)
    {
        ll nleft = (H[i] - chi - 1);
        while (vspec.size() && nleft >= (i - vspec.back()))
        {
            nleft -= (i - vspec.back());
            vspec.pop_back();
            chi++;
        }
        if (!vspec.size())
        {
            ll nadd = (nleft / (i + 1));
            chi += nadd;
            nleft -= nadd * (i + 1);
            if (nleft)
            {
                vspec.push_back(nleft - 1);
            }
            chi++;
        }
        else
        {
            vspec[vspec.size() - 1] += nleft;
            chi++;
        }
        /*for (int x : vspec) cout << x << " ";
        cout << "\n";
        cout << "chi " << chi << "\n";*/
    }
    for (int i = 0; i < N - 1; i++)
        res[i] = -1;
    for (int x : vspec)
        res[x] = 0;

    res[N-1] = chi;
    for (int i = N-2; i >= 0; i--)
    {
        res[i] += res[i+1];
    }
    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}