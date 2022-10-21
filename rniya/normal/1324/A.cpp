#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        int odd=1,even=1;
        for (;n--;){
            int a; cin >> a;
            if (!(a&1)) odd=0;
            else even=0;
        }
        cout << (odd||even?"YES":"NO") << '\n';
    }
}