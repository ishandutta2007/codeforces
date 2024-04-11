#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N;
int arr[MAXN];
int taken[MAXN];

int gcow()
{
    for (int i = 0; i <= N; i++)
        taken[i] = 0;
    for (int i = 0; i < N; i++)
        taken[arr[i]] = 1;

    int res = 0;
    while (taken[res]) res++;
    return res;
}

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector <int> res;
    while (true)
    {
        bool bad = false;
        for (int i = 0; i + 1 < N; i++)
        {
            if (arr[i] > arr[i+1])
                bad = true;
        }
        if (!bad) break;

        int v = gcow();
        if (v < N)
        {
            res.push_back(v);
            arr[v] = v;
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                if (arr[i] != i)
                {
                    res.push_back(i);
                    arr[i] = N;
                    break;
                }
            }
        }
    }

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        if (i) cout << " ";
        cout << res[i] + 1;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}