#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, mod;
    long long a[2005];
    cin >> n;
    mod = n + 1;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << n + 1 << endl;
    for(int i = n; i > 0; i--)
    {
        int add = 0;
        for(int j = 1; j <= mod; j++)
        {
            if((a[i] + j) % mod == i)
            {
                add = j;
                cout << "1 " << i << " " << add << endl;
                for(int k = n - 1; k >= 1; k--)
                    a[k] += add;
                break;
            }
        }
    }
    cout << 2 << " " << n << " " << mod << endl;
}