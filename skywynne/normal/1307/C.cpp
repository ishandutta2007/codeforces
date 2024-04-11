// Skywynne
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q, A[N];;
long long D[26], C[26][26];
string S;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> S;
    n = (int)S.size();
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < 26; j ++)
            C[S[i] - 'a'][j] += D[j];
        D[S[i] - 'a'] ++;
    }
    long long Mx = * max_element(D, D + 26);
    for (int i = 0; i < 26; i ++)
        for (int j = 0; j < 26; j ++)
            Mx = max(Mx, C[i][j]);
    return !printf("%lld\n", Mx);
}