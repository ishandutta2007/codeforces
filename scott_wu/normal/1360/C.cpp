#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int arr[55];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort (arr, arr + N);
    bool bb = false;
    int ne = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] % 2 == 0) ne++;
        if (i + 1 < N && arr[i] + 1 == arr[i+1])
            bb = true;
    }
    if (bb || (ne % 2 == 0))
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        gogo();
    }
}