#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
ll arr[MAXN];

void gogo()
{
    cin >> N;
    ll S = 0, X = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        S += arr[i];
        X ^= arr[i];
    }
    cout << "2\n";
    cout << X << " " << S + X << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}