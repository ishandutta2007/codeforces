#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gogo()
{
    ll N, A, B;
    cin >> N >> A >> B;

    ll v = 1;
    bool works = false;
    while (v <= N)
    {
        if (N % B == v % B) works = true;
        v = v * A;
        if (A == 1) break;
    }
    if (works) cout << "Yes\n";
    else cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}