#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, r, t, p, c, A[N];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r;
        t += abs(r);
    }
    cout << t;
    return (0);
}