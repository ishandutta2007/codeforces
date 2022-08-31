#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, M;
int arr[MAXN];
priority_queue <pair <int, int> > q;

bool gtry (int d, int x)
{
    if (q.size() >= M && q.top().first <= d)
        return false;
    q.push(make_pair (d, x));
    if (q.size() > M) q.pop();
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort (arr, arr + N);
    for (int i = 1; i <= M; i++)
    {
        gtry (i, arr[0] - i);
        gtry (i, arr[N-1] + i);
    }

    for (int i = 0; i + 1 < N; i++)
    {
        int lo = arr[i], hi = arr[i+1];
        int mid = (lo + hi) / 2;
        for (int j = lo + 1; j <= mid; j++)
            if (!gtry (j - lo, j))
                break;
        for (int j = hi - 1; j > mid; j--)
            if (!gtry (hi - j, j))
                break;
    }

    vector <int> ans;
    ll ct = 0;
    while (!q.empty())
    {
        ans.push_back(q.top().second);
        ct += q.top().first;
        q.pop();
    }
    cout << ct << "\n";
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
}