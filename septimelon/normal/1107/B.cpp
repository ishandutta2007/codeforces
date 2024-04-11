#include <iostream>

using namespace std;

int main()
{
    long long n, k[1000], x[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> k[i] >> x[i];
    for (int i = 0; i < n; i++)
    {
        cout << x[i]+9*(k[i]-1) << endl;
    }
    return 0;
}