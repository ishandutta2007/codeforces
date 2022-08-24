#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, P;
string S;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> P >> S;
    if (P == 1)
    {
        cout << "NO\n";
        return 0;
    }
    if (P == 2)
    {
        if (S[0] == 'b') cout << "NO\n";
        else
        {
            if (N == 1) cout << "b\n";
            else cout << "ba\n";
        }
        return 0;
    }

    vector <int> v;
    for (int i = N - 1; i >= 0; i--)
    {
        bool done = false;
        for (int j = S[i] - 'a' + 1; j < P; j++)
        {
            bool bad = false;
            for (int k = max (i - 2, 0); k < i; k++)
                if (j == S[k] - 'a')
                    bad = true;
            if (bad) continue;
            if (!bad)
            {
                for (int k = 0; k < i; k++)
                {
                    v.push_back(S[k] - 'a');
                }
                v.push_back(j);
                done = true;
                break;
            }
        }
        if (done) break;
    }
    if (!v.size())
    {
        cout << "NO\n";
        return 0;
    }

    for (int i = v.size(); i < N; i++)
    {
        int lo = 0;
        while (lo == v[i-1] || (i > 1 && lo == v[i-2]))
            lo++;
        v.push_back(lo);
    }

    for (int i = 0; i < N; i++)
        cout << (char) ('a' + v[i]);
    cout << "\n";
}