#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
string S;

void gogo()
{
    cin >> S;
    N = S.length();

    int ans = 0;
    for (int i = 1; i < N; i++)
    {
        if (S[i] == S[i-1] || S[i] == S[i-2])
        {
            S[i] = '-';
            ans++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}