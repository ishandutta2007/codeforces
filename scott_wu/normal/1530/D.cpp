#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
int arr[MAXN];
vector <int> v[MAXN];
set <int> nleft;

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i]--;

        v[arr[i]].push_back(i);
    }

    for (int i = 0; i < N; i++)
        if (!v[i].size())
            nleft.insert(i);

    cout << N - nleft.size() << "\n";
    for (int i = 0; i < N; i++)
    {
        if (v[i].size() > 1)
        {
            bool found = false;
            for (int j = 0; j + 1 < v[i].size(); j++)
            {
                int x = v[i][j];
                bool seen = false;
                for (int y : nleft)
                {
                    if (x != y)
                    {
                        arr[x] = y;
                        nleft.erase(y);
                        seen = true;
                        break;
                    }
                }
                if (!seen) found = true;
            }
            if (found)
            {
                int x = v[i].back();
                for (int y : nleft)
                {
                    if (x != y)
                    {
                        arr[x] = y;
                        nleft.erase(y);
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << arr[i] + 1;
    }
    cout << "\n";

    for (int i = 0; i <= N; i++)
    {
        arr[i] = 0;
        v[i].clear();
    }
    nleft.clear();
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}