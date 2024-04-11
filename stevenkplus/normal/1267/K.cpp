#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
vector <int> v;

void gogo()
{
    cin >> N;
    v.clear();

    int cv = 2;
    while (N)
    {
        v.push_back ((int) (N % cv));
        N /= cv;
        cv++;
    }

    sort (v.begin(), v.end());

    ll res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (!v[i]) continue;

        vector <int> v2;
        for (int j = 0; j < v.size(); j++)
            if (j != i)
                v2.push_back(v[j]);

        ll ctot = 1;
        for (int j = 0; j < v2.size(); j++)
        {
            int nt = -j;
            for (int x : v2)
                if (x <= j + 1)
                    nt++;
            ctot *= nt;
        }
        res += ctot;
    }

    int clast = -1, cs = 0;
    for (int x : v)
    {
        if (x != clast)
        {
            clast = x;
            cs = 0;
        }

        cs++;
        res /= cs;
    }

    cout << res - 1 << "\n";
}

int T;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        gogo();
    }
}