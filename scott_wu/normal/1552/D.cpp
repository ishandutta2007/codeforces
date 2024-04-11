#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 12;

int N;
int arr[MAXN];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int rp = 1;
    for (int i = 0; i < N; i++) rp *= 3;

    int ans = 0;
    for (int t = 0; t < rp; t++)
    {
        int nt = t;

        int tot = 0;
        for (int i = 0; i < N; i++)
        {
            int p = nt % 3;
            if (p == 1) tot += arr[i];
            else if (p == 2) tot -= arr[i];
            nt /= 3;
        }
        if (tot == 0) ans++;
    }
    if (ans > 1) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}