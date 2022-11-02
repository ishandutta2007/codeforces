#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, d, A[N];
map < int , int > M;
int main()
{
    cin  >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r;
        if (r)
        M[r] = 1;
    }
    cout << M.size();
    return (0);
}