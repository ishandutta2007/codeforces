// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, m, q, A[N];
string S[N], T[N];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        cin >> S[i];
    for (int j = 0; j < m; j ++)
        cin >> T[j];
    cin >> q;
    for (; q; q --)
    {
        int a;
        cin >> a; a --;
        cout << S[a % n] + T[a % m] << "\n";
    }
    return 0;
}