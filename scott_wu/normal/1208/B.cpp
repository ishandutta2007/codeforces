#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2100;

int N;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    set <int> s;
    int ans = N;
    for (int i = 0; i <= N; i++)
    {
        s.clear();
        for (int j = 0; j < i; j++)
            s.insert(arr[j]);
        if ((int) s.size() != i)
            break;

        ans = min (ans, N - i);
        for (int j = N - 1; j >= i; j--)
        {
            if (s.find(arr[j]) != s.end())
                break;
            s.insert(arr[j]);
            ans = min (ans, j - i);
        }
    }
    cout << ans << "\n";
}