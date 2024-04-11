#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
int arr[MAXN];
bool used[MAXN];

int get_lo()
{
    for (int i = 0; i < MAXN; i++)
        used[i] = false;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int x = arr[i];
        if (used[x-1] || used[x] || used[x+1]) continue;
        ans++;
        used[x+1] = true;
    }
    return ans;
}

int get_hi()
{
    for (int i = 0; i < MAXN; i++)
        used[i] = false;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int x = arr[i];
        if (used[x-1] && used[x] && used[x+1]) continue;
        ans++;
        if (!used[x-1]) used[x-1] = true;
        else if (!used[x]) used[x] = true;
        else used[x+1] = true;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);

    cout << get_lo() << " " << get_hi() << "\n";
}