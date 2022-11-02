#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, NX = 1e9 + 7;
int n, r, t, p, c, A[N];
bool Check(int m)
{
    int cc = 0;
    while (m != 0)
    {
        cc += m % 10;
        m /= 10;
    }
    return (cc == 10);
}
int main()
{
    cin >> n;
    int i = 1;
    while (1)
    {
        if (Check(i))
            c ++;
        if (c == n)
            break;
        i ++;
    }
    cout << i;
    return (0);
}