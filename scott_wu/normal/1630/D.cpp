#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N, M;
int arr[MAXN];
int v;

int gcd (int a, int b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}

ll get_ans()
{
    ll tot = 0;
    for (int i = 0; i < v; i++)
    {
        vector <int> r;
        int nneg = 0;
        for (int j = i; j < N; j += v)
        {
            if (arr[j] < 0) nneg++;
            r.push_back(abs (arr[j]));
        }

        sort (r.begin(), r.end());
        if (nneg % 2 == 1)
        {
            tot -= r[0];
        }
        else
            tot += r[0];

        for (int j = 1; j < r.size(); j++)
            tot += r[j];
    }
    return tot;
}

void gogo()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    v = 0;
    for (int i = 0; i < M; i++)
    {
        int g; cin >> g;
        if (v == 0) v = g;
        else v = gcd (v, g);
    }

    ll res = get_ans();
    for (int i = 0; i < v; i++)
        arr[i] = -arr[i];
    res = max (res, get_ans());
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}