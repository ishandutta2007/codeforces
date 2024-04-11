#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector <pair <ll, ll> > pp;

bool cmp (pair <ll, ll> a, pair <ll, ll> b)
{
    return a.first * b.second > a.second * b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;

        int ns = 0, nh = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 's') ns++;
            if (s[j] == 'h')
            {
                nh++;
                ans += ns;
            }
        }
        pp.push_back (make_pair (ns, nh));
    }

    sort (pp.begin(), pp.end(), cmp);
    ll ns = 0;
    for (int i = 0; i < N; i++)
    {
        ans += pp[i].second * ns;
        ns += pp[i].first;
    }
    cout << ans << "\n";
}