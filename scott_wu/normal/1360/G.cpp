#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcf (int a, int b)
{
    if (b == 0) return a;
    return gcf (b, a % b);
}

void gogo()
{
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    if (N * A != M * B)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int nn = A, nd = M;
    int g = gcf (nn, nd);
    nn /= g;
    nd /= g;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if ((i + j) % nd < nn)
                cout << '1';
            else
                cout << '0';
        }
        cout << "\n";
    }
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