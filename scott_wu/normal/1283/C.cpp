#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
int arr[MAXN];
bool used[MAXN];

vector <int> u, v;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i]--;
        used[arr[i]] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        if (!used[i])
            u.push_back(i);
        if (arr[i] == -1)
            v.push_back(i);
    }

    for (int x = 0; x < u.size(); x++)
    {
        if (u[x] == v[x] || (x + 2 == u.size() && u[x+1] == v[x+1]))
            swap (v[x], v[x+1]);
        arr[v[x]] = u[x];
    }

    for (int i = 0; i < N; i++)
        cout << arr[i] + 1 << " ";
}