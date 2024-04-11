#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;

int main()
{
    int n;
    cin >> n;
    ll a[102];
    PP p[102];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ll l = a[i];
        int j;
        for(j = 0; j < 100; j++){
            if(a[i] % 3) break;
            a[i] /= 3;
        }
        int k;
        for(k = 0; k < 100; k++){
            if(a[i] % 2) break;
            a[i] /= 2;
        }
        p[i] = PP(P(-j, k), l);
    }
    sort(p, p + n);
    for(int i = 0; i < n; i++) cout << p[i].second << " ";
    cout << endl;
}