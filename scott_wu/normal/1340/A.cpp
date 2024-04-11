#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int arr[MAXN];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int mlo = 1e9;
    bool bad = false;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] >= mlo && arr[i] != arr[i-1] + 1)
            bad = true;
        mlo = min (mlo, arr[i]);
    }
    if (bad) cout << "No\n";
    else cout << "Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}