#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
    {

    int N, X;

    int K = 0;
    cin >> N >> X;
    for (int i = 0; i < N; i++)
    {
        int c; cin >> c;
        if (c % 2 == 1) K++;
    }

    if ((X == 1 && K == 0) || (X == N && K % 2 == 0) || K == 0 || (K == N && X % 2 == 0))
        cout << "No\n";
    else
        cout << "Yes\n";
}
}