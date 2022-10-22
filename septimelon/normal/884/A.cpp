#include <iostream>

using namespace std;

int main()
{
    int n, t, a[100];
    cin >> n >> t;
    for (int i=0; i<n; i++)
        cin >> a[i];
    int k=0;
    while (t>0)
    {
        t-=(86400-a[k]);
        k++;
    }
    cout << k;
    return 0;
}