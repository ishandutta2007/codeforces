#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        int A, B, N;
        cin >> A >> B >> N;
        if (N % 3 == 0)
            cout << A << "\n";
        else if (N % 3 == 1)
            cout << B << "\n";
        else
            cout << (A ^ B) << "\n";
    }
}