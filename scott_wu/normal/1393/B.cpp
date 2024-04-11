#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
int arr[100100];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        arr[x]++;
    }

    int p2 = 0, p4 = 0;
    for (int i = 0; i < 100100; i++)
    {
        p2 += arr[i] / 2;
        p4 += arr[i] / 4;
    }

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        char c;
        int x;
        cin >> c >> x;
        p2 -= arr[x] / 2;
        p4 -= arr[x] / 4;

        if (c == '+') arr[x]++;
        else arr[x]--;
        p2 += arr[x] / 2;
        p4 += arr[x] / 4;

        if (p2 >= 4 && p4 >= 1)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}