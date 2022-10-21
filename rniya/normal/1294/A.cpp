#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int a,b,c,n; cin >> a >> b >> c >> n;
        n+=a+b+c;
        int ok=1;
        if (n%3!=0) ok=0;
        n/=3;
        if (n<a||n<b||n<c) ok=0;
        cout << (ok?"YES":"NO") << '\n';
    }
}