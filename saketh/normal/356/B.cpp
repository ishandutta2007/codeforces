#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
using namespace std;

typedef long long ll;

ll N, M;
ll X, Y, g, l;
string x, y;

int occ[1000005][26];

int main(){
    cin >> N >> M >> x >> y;

    X = x.size();
    Y = y.size();
    g = __gcd(X, Y);
    l = X * Y / g; 

    for(int i=0; i<X; i++)
        occ[i%g][x[i]-'a']++;

    ll ans = 0;
    for(int i=0; i<Y; i++)
        ans += l/Y - occ[i%g][y[i]-'a'];

    cout << ans * (N * X / l) << endl;
}