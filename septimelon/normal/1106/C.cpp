#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a(300000);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a.rbegin(), a.rend());
    /*for (int i = 0; i < n; i++)
        cout << a[i] << " ";*/
    long long k = 0;
    int n1 = n/2;
    for (int i = 0; i < n1; i++)
    {
        k += ((long long)a[i] + (long long)a[n-i-1])*((long long)a[i] + (long long)a[n-i-1]);
    }
    cout << k << endl;
    return 0;
}