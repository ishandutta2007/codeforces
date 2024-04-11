#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const ll MOD = 1e9 + 7;

int X;
string S;
int rv[MAXN];

void gogo()
{
    cin >> X >> S;
    for (int i = 0; i < S.length(); i++)
        rv[i] = S[i] - '0';

    ll N = S.length();
    ll nv = N;
    for (int i = 1; i <= X; i++)
    {
        int nt = rv[i-1];
        ll nn = min (i + (N - i) * nt, (ll) X + 1);
        for (int j = N; j < nn; j++)
            rv[j] = rv[j - (N - i)];
        N = nn;

        nv = (i + (nv - i) * nt) % MOD;
        nv = (nv + MOD) % MOD;
    }
    cout << nv << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}