#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[100100];

void gogo()
{
    int N, m=0, c=0;
    cin >> N;
    for (int i = 0; i <= N; i++)
        arr[i] = 0;

    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        arr[x]++;
    }

    for (int i = 1; i <= N; i++)
    {
        int x = arr[i];
        if (x > m)
        {
            m = x;
            c = 0;
        }
        if (x == m)
            c++;
    }

    cout << (N - c) / (m - 1) - 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}