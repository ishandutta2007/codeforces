#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector <int> v;

void gogo()
{
    cin >> N;
    v.clear();

    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        if (x == 1)
        {
            v.push_back(1);
        }
        else
        {
            while (v[v.size() - 1] != x - 1)
                v.pop_back();
            v[v.size() - 1]++;
        }

        for (int j = 0; j < v.size(); j++)
        {
            if (j) cout << ".";
            cout << v[j];
        }
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