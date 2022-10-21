#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n,k; cin >> n >> k;
        cout << n/k*k+min(n%k,k/2) << '\n';
    }
}