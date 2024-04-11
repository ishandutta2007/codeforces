#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int arr[MAXN];
int nv[50];

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 50; i++)
        nv[i] = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < 30; j++)
            if (arr[i] & (1 << j))
                nv[j]++;
    }

    int cv = 30;
    while (cv >= 0 && nv[cv] != 1)
        cv--;

    if (cv >= 0)
    {
        for (int i = 0; i < N; i++)
            if (arr[i] & (1 << cv))
            {
                swap (arr[i], arr[0]);
                break;
            }
    }

    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << "\n";
}