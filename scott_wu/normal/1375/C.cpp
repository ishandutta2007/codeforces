#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int arr[300100];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    if (arr[0] > arr[N-1])
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}