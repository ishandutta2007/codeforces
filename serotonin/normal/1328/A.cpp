#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=505;

int main()
{
    int tcs;
    cin >> tcs;
    while(tcs--) {
        ll a, b;
        cin >> a >> b;
        ll x = (a+b-1)/b;
        cout << abs(x*b-a) << endl;
    }
}