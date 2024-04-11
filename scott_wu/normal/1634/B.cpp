#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = (1 << 16) + 100;
 
ll N, X, Y;
 
void gogo()
{
    cin >> N >> X >> Y;
    for (int i = 0; i < N; i++)
    {
        ll a; cin >> a;
        X ^= a;
    }

    if ((X + Y) % 2 == 0)
        cout << "Alice\n";
    else
        cout << "Bob\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}