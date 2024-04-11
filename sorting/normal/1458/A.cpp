#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b){
    if(!b) return a;
    return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    vector<ll> b(m);

    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i)
        cin >> b[i];

    for(int i = 1; i < n; ++i)
        a[i] = abs(a[i] - a[0]);

    ll g = 0;
    for(int i = 1; i < n; ++i)
        g = gcd(g, a[i]); 

    for(int i = 0; i < m; ++i){
        cout << gcd(b[i] + a[0], g) << " ";
    }
    cout << "\n";
}