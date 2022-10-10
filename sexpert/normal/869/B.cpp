#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    if(b - a >= 5)
    {
        cout << 0;
        return 0;
    }
    if(a == b)
    {
        cout << 1;
        return 0;
    }
    int d = b - a;
    b %= 10ll;
    int res = b;
    for(int i = 0; i < d - 1; i++)
    {
        res *= (b - i - 1);
    }
    if(res < 0) res += 10;
    cout << res%10;
}