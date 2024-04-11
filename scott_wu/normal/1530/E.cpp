#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
string S;
int nc[26];
vector <pair <int, int> > v;

char cc (int x)
{
    return (char) ('a' + x);
}

void gogo()
{
    cin >> S;
    N = S.length();

    for (int i = 0; i < 26; i++)
        nc[i] = 0;
    v.clear();

    for (int i = 0; i < N; i++)
    {
        nc[S[i]-'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (nc[i])
            v.push_back (make_pair (i, nc[i]));
    }

    int K = v.size();
    if (K == 1)
    {
        cout << S << "\n";
        return;
    }

    int sloc = -1;
    for (int i = 0; i < K; i++)
    {
        if (v[i].second == 1)
        {
            sloc = i; break;
        }
    }
    if (sloc != -1)
    {
        cout << cc (v[sloc].first);
        for (int i = 0; i < K; i++)
        {
            if (i == sloc) continue;
            for (int j = 0; j < v[i].second; j++)
                cout << cc (v[i].first);
        }
        cout << "\n";
        return;
    }

    if (v[0].second <= (N / 2 + 1))
    {
        cout << cc (v[0].first);
        v[0].second--;
        for (int i = 1; i < K; i++)
        {
            for (int j = 0; j < v[i].second; j++)
            {
                if (v[0].second)
                {
                    cout << cc (v[0].first);
                    v[0].second--;
                }
                cout << cc (v[i].first);
            }
        }
        if (v[0].second) cout << cc (v[0].first);
        cout << "\n";
        return;
    }

    if (K >= 3)
    {
        cout << cc (v[0].first);
        v[0].second--;
        cout << cc (v[1].first);
        v[1].second--;
        for (int i = 0; i < v[0].second; i++)
            cout << cc (v[0].first);
        cout << cc (v[2].first);
        v[2].second--;

        /*for (int i = 0; i < v[1].second; i++)
            cout << cc (v[1].first);
        cout << cc (v[2].first);
        v[2].second--;*/

        for (int i = 1; i < K; i++)
        {
            for (int j = 0; j < v[i].second; j++)
                cout << cc (v[i].first);
        }
        cout << "\n";
        return;
    }

    {
        cout << cc (v[0].first);
        for (int i = 0; i < v[1].second; i++)
            cout << cc (v[1].first);
        for (int i = 0; i < v[0].second - 1; i++)
            cout << cc (v[0].first);
        /*cout << cc (v[1].first) << cc (v[1].first);
        v[1].second -= 2;
        while (v[0].second)
        {
            cout << cc (v[0].first);
            if (v[1].second == v[0].second)
            {
                cout << cc (v[1].first);
                v[1].second--;
            }
            v[0].second--;
        }*/
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}