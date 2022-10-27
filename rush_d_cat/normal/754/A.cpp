#include <iostream>
using namespace std;
int n;
int sum[102], a[102];
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum[i] = a[i] + sum[i-1];
    }
    int ok = 0, x;
    if(sum[n])
    {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        if(sum[i]!=0 && (sum[n] - sum[i] != 0))
        {
            x = i;
            ok = 1;
        }
    }
    if(ok)
    {
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << 1 << " " << x << endl;
        cout << (x+1) << " " << n << endl;
    } else {
        cout << "NO" << endl;
    }

}