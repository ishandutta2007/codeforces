#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[310];

int main()
{
    ios_base::sync_with_stdio(0);
    int P, N;
    cin >> P >> N;

    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        x %= P;
        if (arr[x])
        {
            cout << i + 1 << "\n";
            return 0;
        }
        arr[x]++;
    }
    cout << "-1\n";
}