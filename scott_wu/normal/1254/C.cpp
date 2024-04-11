#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

ll get_area (int i, int j, int k)
{
    cout << "1 " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    ll res; cin >> res;
    return res;
}

int get_sign (int i, int j, int k)
{
    cout << "2 " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    int res; cin >> res;
    return res;
}

int N;
vector <pair <ll, int> > area;

int main()
{
    cin >> N;
    int pp = 1;
    for (int i = 2; i < N; i++)
    {
        if (get_sign (0, i, pp) > 0)
            pp = i;
    }

    for (int i = 1; i < N; i++)
    {
        if (i == pp) continue;
        area.push_back (make_pair (get_area (0, pp, i), i));
    }
    sort (area.begin(), area.end());
    int big_guy = area.back().second;

    vector <int> ans;
    vector <int> rans;
    ans.push_back(0);
    ans.push_back(pp);
    for (int i = 0; i + 1 < area.size(); i++)
    {
        if (get_sign (0, area[i].second, big_guy) > 0)
            ans.push_back(area[i].second);
        else
            rans.push_back(area[i].second);
    }
    ans.push_back(big_guy);

    reverse(rans.begin(), rans.end());

    cout << 0;
    for (int x : ans)
        cout << " " << x + 1;
    for (int x : rans)
        cout << " " << x + 1;
    cout << endl;
}