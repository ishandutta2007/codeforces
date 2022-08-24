#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N;
pair <int, int> p[MAXN];

pair <int, int> trans (pair <int, int> pp)
{
    int a = pp.first + pp.second;
    int b = pp.first - pp.second;
    if (a % 2)
    {
        a++;
        b++;
    }

    return make_pair (a / 2, b / 2);
}

void gogo()
{
    vector <int> v[2];
    for (int i = 0; i < N; i++)
    {
        v[abs (p[i].first + p[i].second) % 2].push_back(i);
    }

    if (v[0].size() > 0 && v[1].size() > 0)
    {
        cout << v[0].size() << "\n";
        for (int i = 0; i < v[0].size(); i++)
        {
            if (i) cout << " ";
            cout << v[0][i] + 1;
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++)
        p[i] = trans (p[i]);
    gogo();
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    gogo();
}