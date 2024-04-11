#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    n = 1<<n;
    vector<ll> v(n);
    for(auto & x : v)cin >> x;
    double su = 0;
    for(auto x : v)su+=x;
    printf("%.6f\n", su/(double)n);
    while(q--){
        ll z, val; cin >> z >> val;
        su+=val-v[z];
        v[z] = val;
        printf("%.6f\n", su/(double)n);
    }
    
}