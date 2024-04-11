#include <iostream>

using namespace std;

int main()
{
    int n, x, a[100000];
    cin >> n >> x;
    for (int i=0; i<n; i++)
        cin >> a[i];
    int k=n-1;
    for (int i=0; i<n; i++)
        k+=a[i];
    if (k==x)
        cout << "YES";
    else cout << "NO";
}