#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n,m;
    cin >> n >> m;
    if(n > 40) cout << m;
    else cout << (ll)m % ((ll)1 << n);
}