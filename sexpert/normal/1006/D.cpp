#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = 0; i < n/2; i++)
    {
        if((a[i] == a[n - 1 - i]  && b[i] == b[n - 1 - i])||(a[i] == b[i] && a[n - 1 - i] == b[n - 1 - i]) || (a[i] == b[n - 1 - i] && a[n - 1 - i] == b[i])) ans += 0;
        else if(a[i] == b[i] || a[i] == b[n - 1 - i] || a[n - 1 - i] == b[i] || a[n - 1 - i] == b[n - 1 - i] || b[i] == b[n - 1 - i]) ans++;
        else ans += 2;
    }
    if(n%2 && a[n/2] != b[n/2]) ans++;
    cout << ans;
}