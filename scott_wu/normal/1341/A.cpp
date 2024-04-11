#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, A, B, C, D;

void gogo()
{
    cin >> N >> A >> B >> C >> D;
    if ((A + B) * N >= C - D && (A - B) * N <= C + D)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}