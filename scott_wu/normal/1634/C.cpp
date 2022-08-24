#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = (1 << 16) + 100;
 
int N, K;
 
void gogo()
{
    cin >> N >> K;
    if (N % 2 == 1 && K > 1)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < N; i++)
    {
        int p = (i / 2) * 2 * K + i % 2;
        for (int j = 0; j < K; j++)
        {
            if (j) cout << " ";
            cout << p + 2 * j + 1;
        }
        cout << "\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}