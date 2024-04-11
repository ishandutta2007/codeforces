#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gogo()
{
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        if (i % 2 == 0)
        {
            if (x > 0) x = -x;
        }
        else
        {
            if (x < 0) x = -x;
        }
        if (i) cout << " ";
        cout << x;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}