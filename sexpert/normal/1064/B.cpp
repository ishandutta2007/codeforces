#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long p2[32];
    p2[0] = 1;
    for(int i = 1; i < 32; i++)
        p2[i] = 2*p2[i - 1];
    int t;
    cin >> t;
    while(t--)
    {
        int a;
        cin >> a;
        int pc = __builtin_popcount(a);
        cout << p2[pc] << endl;
    }
}