#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m){
    if(m == 0) return n;
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    ll a[200005], b[200005];
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a + n);
    for(int i = 0; i < m; i++) scanf("%lld", &b[i]);
    ll g = 0;
    for(int i = 1; i < n; i++) g = gcd(g, a[i] - a[i - 1]);
    for(int i = 0; i < m; i++){
        cout << gcd(g, a[0] + b[i]) << " ";
    }
    cout << endl;
}