#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
int av[MAXN];
double dv[MAXN];

vector <pair <int, ll> > v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> av[i];


    for (int i = 0; i < N; i++)
    {
        ll cv = av[i];
        int cs = 1;
        ll cg = cv;
        while (v.size() > 0)
        {
            int ns = v.back().first;
            ll ng = v.back().second;
            if (ng * cs > cg * ns)
            {
                cs += ns;
                cg += ng;
                v.pop_back();
            }
            else
                break;
        }
        v.push_back(make_pair (cs, cg));
    }

    int cloc = 0;
    for (auto it : v)
    {
        int np = it.first;
        double nval = (it.second + 0.0) / np;
        for (int i = 0; i < np; i++)
            dv[cloc++] = nval;
    }

    cout << fixed << setprecision(10);
    for (int i = 0; i < N; i++)
        cout << dv[i] << "\n";
}