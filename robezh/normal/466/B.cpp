#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
double EPS = 1e-6;
ll n,a,b;

int main(){
    cin >> n >> a >> b;
    n *= 6;
    if(a * b >= n){
        printf("%I64d\n", a * b);
        printf("%I64d %I64d", a, b);
        return 0;
    }
    bool swapped = (a > b);
    if(swapped){ll tmp = a; a = b; b = tmp;}

    ll minres = (ll)1e18, ra, rb;
    ll maxa = min((n+b-1)/b, (ll)(sqrt(n)+EPS));
    for(ll i = a; i <= maxa; i++){
        ll j = (n+i-1)/i;
        if(j >= b && i * j < minres){
            minres = i * j;
            ra = i, rb = j;
        }
    }

    if(swapped){ll tmp = ra; ra = rb, rb = tmp;}
    cout << minres << endl;
    cout << ra << " " << rb;

}