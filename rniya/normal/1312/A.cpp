#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n,m; cin >> n >> m;
        cout << (n%m==0?"YES":"NO") << '\n';
    }
}