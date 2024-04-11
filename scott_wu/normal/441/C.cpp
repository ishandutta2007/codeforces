#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M, K;
vector <pair <int, int> > v;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int y = j;
            if (i % 2)
                y = M - 1 - y;
            v.push_back(make_pair (i + 1, y + 1));
        }
    }

    for (int i = 0; i < K - 1; i++)
    {
        cout << 2;
        for (int j = 0; j < 2; j++)
            cout << " " << v[2*i+j].first << " " << v[2*i+j].second;
        cout << "\n";
    }
    cout << v.size() - 2 * (K - 1);
    for (int i = 2 * (K - 1); i < v.size(); i++)
    {
        cout << " " << v[i].first << " " << v[i].second;
    }
    cout << "\n";
}