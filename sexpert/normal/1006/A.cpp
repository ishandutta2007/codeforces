#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[1010];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i]%2) cout << a[i];
        else cout << a[i] - 1;
        cout << " ";
    }
}