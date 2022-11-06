#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=5e5+5;

ll a[sz];

int main()
{
    ll b,g,n;
    cin >> b >> g >> n;
    b=min(b,n);
    g=min(g,n);
    cout << b+g-n+1;
}